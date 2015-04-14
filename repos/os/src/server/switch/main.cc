/*
 * \brief  Testing 'printf()' with negative integer
 * \author Christian Prochaska
 * \date   2012-04-20
 *
 */

/*
 * Copyright (C) 2012-2013 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

#include <kernel/interface.h> 
#include <base/printf.h>
#include <base/env.h>

int main(int argc, char **argv)
{
	
	using namespace Genode;
	
	Genode::printf("-1 = %d = %ld\n", -1, -1L);	
	
	PERR("SMC call .. ");
	Kernel::switch_nw_sw();

	PERR("After the smc call ..");
	return 0;
}
