#include "../include/csr_core.h"
#include "../include/csr_imc.h"


int main()
{

    init_csr();
    init_memctrs();
    print_memctrs();
	init_pmon_ctrs();
	pmon_config(0x0, 0x0, 0x0, 0x0, 0x1, 0x00, 0);
	pmon_config(0x0, 0x0, 0x0, 0x0, 0x0, 0x09, 1);
	pmon_config(0x0, 0x0, 0x0, 0x0, 0x1, 0x02, 2);
	pmon_config(0x0, 0x0, 0x0, 0x0, 0x1, 0x04, 3);
	pmon_config(0x0, 0x0, 0x0, 0x0, 0x1, 0x05, 4);
	// The data from this is not meant to be meaningful, its just a test
	// Hopefully you wont see all 0s
	print_pmon_ctrs();
	// can be READ_BW, WRITE_BW, or ALL_BW
	mem_bw_on_ctr(0, ALL_BW);
	print_mem_bw_from_ctr(0);
    finalize_csr();
	return 0;
}