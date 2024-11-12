/* **LINKER.LD**
 * Low-level linker file for
 * configuring linking.
 */

ENTRY(start)

SECTIONS
{
	. = 1M;

	.boot :
	{
		KEEP(*(.multiboot_header))
	}

	.text :
	{
		*(.text)
	}
}
