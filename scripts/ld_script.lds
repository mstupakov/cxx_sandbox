SECTIONS
{
  .init_array :
  {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*) SORT(.ctors.*)))
    KEEP (*(.init_array .ctors))
    PROVIDE_HIDDEN (__init_array_end = .);
  }
  .fini_array :
  {
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*) SORT(.dtors.*)))
    KEEP (*(.fini_array .dtors))
    PROVIDE_HIDDEN (__fini_array_end = .);
  }
}
