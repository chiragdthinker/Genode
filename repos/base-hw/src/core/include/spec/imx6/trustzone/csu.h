/*
 * \brief  Driver for the Central Security Unit for i.MX6
 * \author Stefan Kalkowski
 * \Modified by Chirag Garg
 * \date   2015-03-27
 */

/*
 * Copyright (C) 2012 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

#ifndef _CSU_H_
#define _CSU_H_

/* Genode includes */
#include <util/mmio.h>
#include <util/register.h>

namespace Genode {

	class Csu : Mmio
	{
		private:

			template <off_t OFF>
			struct Csl : public Register<OFF, 32>
			{
				enum {
					SECURE   = 0x33,
					UNSECURE = 0xff,
				};

				struct Slave_a : Register<OFF, 32>::template Bitfield<16, 9>  { };
				struct Slave_b : Register<OFF, 32>::template Bitfield<0, 9> { };
			};

			struct Master : public Register<0x218, 32>
			{
				enum {
					SECURE_UNLOCKED,
					UNSECURE_UNLOCKED,
					SECURE_LOCKED,
					UNSECURE_LOCKED
				};

				struct CP15 : Bitfield<0,2>  { };
				struct Sata : Bitfield<2,2>  { };
				struct Sdma : Bitfield<4,2>  { };
				struct Gpu  : Bitfield<6,2>  { };
				struct Usb  : Bitfield<8,2>  { };
				struct Pcie : Bitfield<10,2> { };
			        struct Rawnand : Bitfield<14,2> { };
				struct Enet : Bitfield<16,2> { };
				struct Dap  : Bitfield<18,2> { };
				struct Usdhc1 : Bitfield<20,2> { };
				struct Usdhc2 : Bitfield<22,2> { };
				struct Usdhc3 : Bitfield<24,2> { };
				struct Usdhc4 : Bitfield<26,2> { };
				struct Hdmi : Bitfield<28,2> { };
			};

			//TODO
			struct Alarm_mask : public Register<0x230, 32> { };
			struct Irq_ctrl   : public Register<0x368, 32> { };

		public:

			typedef Csl<0x00> Csl00;
			typedef Csl<0x04> Csl01;
			typedef Csl<0x08> Csl02;
			typedef Csl<0x0c> Csl03;
			typedef Csl<0x10> Csl04;
			typedef Csl<0x14> Csl05;
			typedef Csl<0x18> Csl06;
			typedef Csl<0x1c> Csl07;
			typedef Csl<0x20> Csl08;
			typedef Csl<0x24> Csl09;
			typedef Csl<0x28> Csl10;
			typedef Csl<0x2c> Csl11;
			typedef Csl<0x30> Csl12;
			typedef Csl<0x34> Csl13;
			typedef Csl<0x38> Csl14;
			typedef Csl<0x3c> Csl15;
			typedef Csl<0x40> Csl16;
			typedef Csl<0x44> Csl17;
			typedef Csl<0x48> Csl18;
			typedef Csl<0x4c> Csl19;
			typedef Csl<0x50> Csl20;
			typedef Csl<0x54> Csl21;
			typedef Csl<0x58> Csl22;
			typedef Csl<0x5c> Csl23;
			typedef Csl<0x60> Csl24;
			typedef Csl<0x64> Csl25;
			typedef Csl<0x68> Csl26;
			typedef Csl<0x6c> Csl27;
			typedef Csl<0x70> Csl28;
			typedef Csl<0x74> Csl29;
			typedef Csl<0x78> Csl30;
			typedef Csl<0x7c> Csl31;
			typedef Csl<0x80> Csl32;
			typedef Csl<0x84> Csl33;
			typedef Csl<0x88> Csl34;
			typedef Csl<0x8c> Csl35;
			typedef Csl<0x90> Csl36;
			typedef Csl<0x94> Csl37;
			typedef Csl<0x98> Csl38;
			typedef Csl<0x9c> Csl39;

			Csu(addr_t const base) : Mmio(base)
			{
				
				/* Audio Group shared control- PWM(1-4) */
				write<Csl00::Slave_b>(Csl00::UNSECURE);
				
				/* Can1 */
				write<Csl00::Slave_a>(Csl00::UNSECURE);
				
				/* Can2 */
				write<Csl01::Slave_b>(Csl00::UNSECURE);
				
				/* Timer Group GPT, EPIT1, EPIT2 */
				write<Csl01::Slave_a>(Csl00::UNSECURE);
				
				/* GPIO1 and GPIO2 */
				write<Csl02::Slave_b>(Csl00::SECURE);
				
				/* GPIO3 and GPIO4 */
				write<Csl02::Slave_a>(Csl00::SECURE);

				/* GPIO5 and GPIO6 */
				write<Csl03::Slave_b>(Csl00::SECURE);
				
				/* GPIO7 */
				write<Csl03::Slave_a>(Csl00::SECURE);
				
				/* KPP */
				write<Csl04::Slave_b>(Csl00::UNSECURE);
				
				/* WDOG1 */
				write<Csl04::Slave_a>(Csl00::UNSECURE);
				
				/* WDOG2 */
				write<Csl05::Slave_b>(Csl00::UNSECURE);
				
				/* Power (CCM, SRC,GPC and SNVS_HP) */
				write<Csl05::Slave_a>(Csl00::UNSECURE);
				
				/* IP2APB */
				write<Csl06::Slave_b>(Csl00::UNSECURE);
				
				/* IOMUX */
				write<Csl06::Slave_a>(Csl00::UNSECURE);
				
				/* DCIC1 and DCIC2 */
				write<Csl07::Slave_b>(Csl00::UNSECURE);
				
				/* SDMA, EPDC */
				write<Csl07::Slave_a>(Csl00::UNSECURE);
				
				/* USBOH3 */
				write<Csl08::Slave_b>(Csl00::UNSECURE);
				
				/* ENET */
				write<Csl08::Slave_a>(Csl00::UNSECURE);
				
				/* MLB150 */
				write<Csl09::Slave_b>(Csl00::UNSECURE);
				
				/* USDHC(1-4) */
				write<Csl09::Slave_a>(Csl00::UNSECURE);
				write<Csl10::Slave_b>(Csl00::UNSECURE);
				write<Csl10::Slave_a>(Csl00::UNSECURE);
				write<Csl11::Slave_b>(Csl00::UNSECURE);
				
				/* I2C(1-3)*/
				write<Csl11::Slave_a>(Csl00::SECURE);
				write<Csl12::Slave_b>(Csl00::SECURE);
				write<Csl12::Slave_a>(Csl00::SECURE);
				
				/* ROMCP */
				write<Csl13::Slave_b>(Csl00::UNSECURE);
				
				/* MMDC Group- VPU */
				write<Csl13::Slave_a>(Csl00::SECURE);
				
				/* WEIM */
				write<Csl14::Slave_b>(Csl00::UNSECURE);
				
				/* OCOTP */
				write<Csl14::Slave_a>(Csl00::UNSECURE);
				
				/* PerfMon Group */
				write<Csl15::Slave_a>(Csl00::UNSECURE);
				
				/* TZASC1 */
				write<Csl16::Slave_b>(Csl00::SECURE);
				
				/* TZASC2 */
				write<Csl16::Slave_a>(Csl00::SECURE);
				
				/* AUDMUX */
				write<Csl17::Slave_b>(Csl00::UNSECURE);
				
				/* CAAM */
				write<Csl17::Slave_a>(Csl00::UNSECURE);
				
				/* SPDIF */
				write<Csl18::Slave_b>(Csl00::UNSECURE);
				
				/*  eCSPI(1-5) */
				write<Csl18::Slave_a>(Csl00::UNSECURE);
				write<Csl19::Slave_b>(Csl00::UNSECURE);
				write<Csl19::Slave_a>(Csl00::UNSECURE);
				write<Csl20::Slave_b>(Csl00::UNSECURE);
				write<Csl20::Slave_a>(Csl00::UNSECURE);
				
				/* UART1 */
				write<Csl21::Slave_b>(Csl00::UNSECURE);
				
				/* ESAI1 */
				write<Csl21::Slave_a>(Csl00::UNSECURE);
				
				/* SSI(1-3)*/
				write<Csl22::Slave_b>(Csl00::UNSECURE);
				write<Csl22::Slave_a>(Csl00::UNSECURE);
				write<Csl23::Slave_b>(Csl00::UNSECURE);
				
				/* ASRC*/
				write<Csl23::Slave_a>(Csl00::UNSECURE);
				
				/* ROMCP */
				write<Csl24::Slave_a>(Csl00::UNSECURE);
				
				/* APBP_DMA */
				write<Csl27::Slave_b>(Csl00::UNSECURE);
				
				/* HDMI */
				write<Csl27::Slave_a>(Csl00::UNSECURE);
				
				/* GPU3D */
				write<Csl28::Slave_b>(Csl00::SECURE);
				
				/* SATA */
				write<Csl28::Slave_a>(Csl00::UNSECURE);
				
				/* OPENVG */
				write<Csl29::Slave_b>(Csl00::UNSECURE);
				
				/* DAP */
				write<Csl29::Slave_a>(Csl00::UNSECURE);
				
				/* HSI */
				write<Csl30::Slave_b>(Csl00::UNSECURE);
				
				/* IPU(1-2) */
				write<Csl30::Slave_a>(Csl00::SECURE);
				write<Csl31::Slave_b>(Csl00::SECURE);
				
				/* WEIM */
				write<Csl31::Slave_a>(Csl00::UNSECURE);
				
				write<Csl32::Slave_b>(Csl00::UNSECURE);
				write<Csl32::Slave_a>(Csl00::UNSECURE);
				write<Csl33::Slave_b>(Csl00::UNSECURE);
				write<Csl33::Slave_a>(Csl00::UNSECURE);
				
				/* VDOA */
				write<Csl34::Slave_b>(Csl00::UNSECURE);
				
				/* UART(2-5)*/
				write<Csl34::Slave_a>(Csl00::UNSECURE);
				write<Csl35::Slave_b>(Csl00::UNSECURE);
				write<Csl35::Slave_a>(Csl00::UNSECURE);
				write<Csl36::Slave_b>(Csl00::UNSECURE);
				
				/* DTCP */
				write<Csl36::Slave_a>(Csl00::UNSECURE);
				
				/* SPBA */
				write<Csl39::Slave_b>(Csl00::UNSECURE);
				
				
				/* DMA from graphical subsystem is considered to be secure */
				write<Master::Gpu>(Master::SECURE_UNLOCKED);

				/* all other DMA operations are insecure */
				write<Master::Sdma>(Master::UNSECURE_UNLOCKED);
				write<Master::Usb>(Master::UNSECURE_UNLOCKED);
				write<Master::Sata>(Master::UNSECURE_UNLOCKED);
				write<Master::Enet>(Master::UNSECURE_UNLOCKED);
				write<Master::Dap>(Master::UNSECURE_UNLOCKED);
				write<Master::Usdhc1>(Master::UNSECURE_UNLOCKED);
				write<Master::Usdhc2>(Master::UNSECURE_UNLOCKED);
				write<Master::Usdhc3>(Master::UNSECURE_UNLOCKED);
				write<Master::Usdhc4>(Master::UNSECURE_UNLOCKED);
				write<Master::Hdmi>(Master::UNSECURE_UNLOCKED);
	
			}
	};
}

#endif /* _CSU_H_ */
