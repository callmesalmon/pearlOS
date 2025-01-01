/*
Copyright 2025 Elis Staaf

Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the LICENSE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
*/

#include <cpu/smbios.h>

typedef struct {
  char EntryPointString[4];    /* This is _SM_ */
  byte Checksum;               /* This value summed with all the values of the table, should be 0 (overflow) */
  byte Length;                 /* Length of the Entry Point Table. Since version 2.1 of SMBIOS, this is 0x1F */
  byte MajorVersion;           /* Major Version of SMBIOS */
  byte MinorVersion;           /* Minor Version of SMBIOS */
  word MaxStructureSize;       /* Maximum size of a SMBIOS Structure (we'll see later) */
  byte EntryPointRevision;     /* ... */
  char FormattedArea[5];       /* ... */
  char EntryPointString2[5];   /* This is _DMI_ */
  byte Checksum2;              /* Checksum for values from EntryPointString2 to the end of table */
  word TableLength;            /* Length of the table containing all the structures */
  uint TableAddress;	       /* Address of the table */
  word NumberOfStructures;     /* Number of structures in the table */
  byte BCDRevision;            /* Unused */
} SMBIOSEntryPoint;

typedef struct {
 	byte Type;
 	byte Length;
 	word Handle;
 } SMBIOSHeader;

SMBIOSHeader* SMBIOS_HEADER_BIOS;

uint32_t smbios_table_len(SMBIOSHeader* hd) {
   uint32_t i;
   const char* strtab = (char*)hd + hd->Length;
   
   /* Scan until we find a double zero byte (\0\0). */
   for (i = 1; strtab[i - 1] != '\0' || strtab[i] != '\0'; i++);
   return hd->Length + i + 1;
}

char* next_string(char* string) {
  uint32_t i = 0;
  while (*(string + i) != 0) ++i;
  return string + i + 1;
}

char* smbios_get_bios_version() {
  char* result = (char*)(SMBIOS_HEADER_BIOS->Length + SMBIOS_HEADER_BIOS);
  return result;
}

char* smbios_get_bios_name() {
  char* result = (char*)(SMBIOS_HEADER_BIOS->Length + SMBIOS_HEADER_BIOS);
  return next_string(result);
}

void smbios_init() {
  char* mem = (uchar*)(0xF0000);
  int length, i;
  unsigned char checksum;
  while ((unsigned int) mem < 0x100000) {
      if (mem[0] == '_' && mem[1] == 'S' && mem[2] == 'M' && mem[3] == '_') {
          length = mem[5];
          checksum = 0;
          for (i = 0; i < length; i++) {
              checksum += mem[i];
          }
          if (checksum == 0) break;
      }
      mem += 16;
  }
  if ((unsigned int) mem == 0x100000) {
    kerror(FIRMWARE_ERROR_SMBIOS_ENTRY_MISSING);
  }
  SMBIOSEntryPoint* smbios_entry_p = (SMBIOSEntryPoint*)(mem);
  SMBIOS_HEADER_BIOS = (SMBIOSHeader*) smbios_entry_p->TableAddress;
}