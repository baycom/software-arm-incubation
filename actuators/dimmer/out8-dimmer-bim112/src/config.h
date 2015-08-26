/*
 *  Copyright (c) 2015 Deti Fliegl <deti@fliegl.de>
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 3 as
 *  published by the Free Software Foundation.
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <sblib/types.h>

#define NO_OF_CHANNELS 8
#define EE_GLOBAL_CFG 0xADF0
#define EE_CHANNEL_CFG_OFFSET 16
#define EE_CHANNEL_CFG_SIZE   256

typedef struct
{
    unsigned int noOfChannels;  //!> how many channels are supported with this hardware
    unsigned short baseAddress; //!> Base address of the config parameters
    byte hardwareVersion[6];    //!> The hardware identification number
    const char *version;
} HardwareVersion;

extern const HardwareVersion * currentVersion;


#define P_InitZeit 0x0000
#define PD_TelegrUnbegr 0x0001
#define P_TelegrUebZeit 0x0002
#define P_InBetrieb 0x0004
#define P_InBetriebValue_0 0x0005
#define P_InBetriebZeit 0x0006
#define SPI_SPEED 0x0008
#define t_EinerFuerAlle 0x0009

#define Anzahl_XY_Paare 0x0000
#define X0 0x0001
#define Y0 0x0002
#define X1 0x0003
#define Y1 0x0004
#define X2 0x0005
#define Y2 0x0006
#define X3 0x0007
#define Y3 0x0008
#define P_Vorzugalage_KanalA 0x0009

#define PD_RampeBitsHanbedienung 0x0020
#define PD_rampenBitsSchalten 0x0021
#define P_RB1 0x0022
#define P_RB2 0x0023
#define PD_RampeBitsZusatz 0x0024
#define PD_RampeSpezial 0x0025

#define P_RelDimmgrenzeUntere 0x0031
#define P_RelDimmgrenzeObere 0x0032
#define P_WertDimmgrenzeUntere 0x0033
#define P_WertDimmgrenzeObere 0x0034

#define P_Zusatzfunktion 0x0040
#define P_EinschaltDimmrampe 0x0043

#define P_AusschaltDimmrampe 0x0045

#define P_relDimmenDimmzeit 0x0047

#define P_WertDimmZeit 0x0049

#define P_Rueckmeldung 0x0051
#define P_RueckmInv 0x0052
#define P_RueckmSenden 0x0053
#define P_StatusWert 0x0054
#define P_StatusSendenWert 0x0055

#define P_VerhBW 0x0058

#define P_PrioritaetFreigeben 0x005f
#define P_VerhPrioritaet 0x0060
#define P_Prior_BSW 0x0061

#define P_Einschalthelligkeit 0x0066

#define P_PresetfunktionFreigeben 0x006e
#define P_SzenenPresetsUeberschr 0x006f
#define P_Preset_2_FunktionEIN 0x0070
#define P_Preset_1_FunktionAUS 0x0071

#define P_Preset_12_Dimmrampe_dimmen 0x0073
#define P_Preset_12_SpeichernInitialisieren 0x0075

#define P_Preset_4_FunktionEIN 0x007b
#define P_Preset_3_FunktionAUS 0x007c

#define P_Preset_34_Dimmrampe_dimmen 0x007e
#define P_Preset_34_SpeichernInitialisieren 0x0080

#define P_SperrfunktionFreigeben 0x0086

#define P_SzenenFreigeben 0x008c
#define SzeneDownloadNichtUeberschreiben 0x008d
#define SzeneBUSNichtUeberschreiben 0x008e
#define P_SzeneFleALichtszene1 0x008f
#define P_SzeneVoreinst1 0x0090
#define P_SzeneUebergangszeit1 0x0091
#define P_SzeneFleALichtszene2 0x0093
#define P_SzeneVoreinst2 0x0094
#define P_SzeneUebergangszeit2 0x0095
#define P_SzeneFleALichtszene3 0x0097
#define P_SzeneVoreinst3 0x0098
#define P_SzeneUebergangszeit3 0x0099
#define P_SzeneFleALichtszene4 0x009b
#define P_SzeneVoreinst4 0x009c
#define P_SzeneUebergangszeit4 0x009d
#define P_SzeneFleALichtszene5 0x009f
#define P_SzeneVoreinst5 0x00a0
#define P_SzeneUebergangszeit5 0x00a1
#define P_SzeneFleALichtszene6 0x00a3
#define P_SzeneVoreinst6 0x00a4
#define P_SzeneUebergangszeit6 0x00a5
#define P_SzeneFleALichtszene7 0x00a7
#define P_SzeneVoreinst7 0x00a8
#define P_SzeneUebergangszeit7 0x00a9
#define P_SzeneFleALichtszene8 0x00ab
#define P_SzeneVoreinst8 0x00ac
#define P_SzeneUebergangszeit8 0x00ad
#define P_SzeneFleALichtszene9 0x00af
#define P_SzeneVoreinst9 0x00b0
#define P_SzeneUebergangszeit9 0x00b1
#define P_SzeneFleALichtszene10 0x00b3
#define P_SzeneVoreinst10 0x00b4
#define P_SzeneUebergangszeit10 0x00b5
#define P_SzeneFleALichtszene11 0x00b7
#define P_SzeneVoreinst11 0x00b8
#define P_SzeneUebergangszeit11 0x00b9
#define P_SzeneFleALichtszene12 0x00bb
#define P_SzeneVoreinst12 0x00bc
#define P_SzeneUebergangszeit12 0x00bd
#define P_SzeneFleALichtszene13 0x00bf
#define P_SzeneVoreinst13 0x00c0
#define P_SzeneUebergangszeit13 0x00c1
#define P_SzeneFleALichtszene14 0x00c3
#define P_SzeneVoreinst14 0x00c4
#define P_SzeneUebergangszeit14 0x00c5
#define P_SzeneFleALichtszene15 0x00c7
#define P_SzeneVoreinst15 0x00c8
#define P_SzeneUebergangszeit15 0x00c9
#define P_SzeneFleALichtszene16 0x00cb
#define P_SzeneVoreinst16 0x00cc
#define P_SzeneUebergangszeit16 0x00cd
#define P_SzeneFleALichtszene17 0x00cf
#define P_SzeneVoreinst17 0x00d0
#define P_SzeneUebergangszeit17 0x00d1
#define P_SzeneFleALichtszene18 0x00d3
#define P_SzeneVoreinst18 0x00d4
#define P_SzeneUebergangszeit18 0x00d5

#define P_SlaveVerhVSW 0x00e0
#define P_TreppeHelligkeit 0x00e1
#define P_SlaveVerhEinschalttelegr 0x00e1
#define P_TreppeZeitdauer_3min 0x00e2
#define P_SlaveVerhDimmen 0x00e2
#define P_SlaveVerhPreset 0x00e3
#define P_TreppeHelligkeitDauerEIN 0x00e4
#define P_TreppeEndeDauerEIN 0x00e5
#define P_TreppeAbdimmzeit 0x00e6
#define P_TreppeWarnung 0x00e8
#define P_TreppeVerhAusschalttelegramm 0x00e9
#define P_TreppeZeitAddierbar 0x00ea

#define P_TreppeHelligkeitNachAbdimmen 0x00ec

#define COMObj_In_Operation   0
#define COMObj_CH_Switch_Status 0
#define COMOBj_CH_Status 1
#define COMOBj_CH_Relative_Dimming 2
#define COMOBj_CH_Brightness_Value 3
#define COMOBj_CH_Status_Brightness_Value 4
#define COMOBj_CH_Rel_Dimming_Speed 5
#define COMOBj_CH_Forced_Operation 6
#define COMOBj_CH_Call_Preset_1_And_2 7
#define COMOBj_CH_Set_Preset_1_And_2 8
#define COMOBj_CH_Call_Preset_3_And_4 9
#define COMOBj_CH_Set_Preset_3_And_4 10
#define COMOBj_CH_8_Bit_Scene 11
#define COMOBj_CH_Restore_Standard_Scene 12
#define COMOBj_CH_Block 13
#define COMOBj_CH_Activate_Staircase_Function 14
#define COMOBj_CH_Permanent_ON 15
#define COMOBj_CH_Duration_Of_Staircase_Lighting 16
#define COMOBj_CH_Warning_Staircase_Lighting 17
#define COMOBj_CH_Statusbyte 24

/* usable pins of io16 hardware

8 x PWM out:
PIO1_4 (IOB1*), timer32_1, MR3
PIO1_2 (IOB2*), timer32_1, MR1
PIO1_1 (IOB3*), timer32_1, MR0
PIO1_7 (IOC0*), timer32_0, MR1
PIO1_6 (IOC1*), timer32_0, MR0
PIO3_2 (IOC3*), timer16_0, MR2
PIO2_8 (IOD0*), timer32_0, MR3
PIO0_8 (SPI_MISO*), timer16_0, MR0
PIO0_9 (SPI_MOSI), timer16_0, MR1

Timmer / Matcher allocation:

timer16_0:
MR0 PIO0_8 (SPI_MISO*)
MR1 PIO0_9 (SPI_MOSI),
MR2 PIO3_2 (IOC3*, PWM).

timer32_0:
MR0 PIO1_6 (IOC1*) or PIO2_5 (IOA0),
MR1 PIO1_7 (IOC0*, XIO4) or PIO2_6 (IOD2),
MR2 PIO0_1 (XIO08) or PIO2_7 (IOD1, XIO7),
MR3 PIO0_11 (XIO23) or PIO2_8 (IOD0*, XIO10).

timer32_1:
MR0 PIO1_1 (IOB3*),
MR1 PIO1_2 (IOB2*),
MR2 PIO1_3 (SWDIO), <- no
MR3 PIO1_4 (IOB1*).

8 x Switch out:

PIO2_5 (IOA0*)
PIO3_5 (IOA1*)
PIO0_7 (IOA2*)
PIO2_9 (IOA3*)
PIO1_11 (IOB0*)
PIO1_5 (IOC2*)
PIO2_7 (IOD1*)
PIO2_6 (IOD2*)
PIO3_3 (IOD3)

 Paramters global start: 27120 / 0x69F0 + 0x4400 = 0xADF0

 27120/0x0000: P_InitZeit
 27121/0x0001: PD_TelegrUnbegr
 27122/0x0002: P_TelegrUebZeit (16bit)
 27124/0x0004: P_InBetrieb
 27125/0x0005: P_InBetriebValue_0
 27126/0x0006: P_InBetriebZeit
 27128/0x0008: SPI_SPEED
 27129/0x0009: t_EinerFuerAlle

 Parameters per channel size: 256 bytes @ 27136 / 0x6A00 + 0x4400 = 0xAE00

 Channel A: 27136 / 0x6A00 + 0x4400 = 0xAE00
 Channel B: 27392 / 0x6B00 + 0x4400 = 0xAF00
 Channel C: 27648 / 0x6C00 + 0x4400 = 0xB000
 Channel D: 27904 / 0x6D00 + 0x4400 = 0xB100
 Channel E: 28160 / 0x6E00 + 0x4400 = 0xB200
 Channel F: 28416 / 0x6F00 + 0x4400 = 0xB300
 Channel G: 28672 / 0x7000 + 0x4400 = 0xB400
 Channel H: 28928 / 0x7100 + 0x4400 = 0xB500

 27136/0x0000: Anzahl der X/Y-Paare
 27137/0x0001: X0
 27138/0x0002: Y0
 27139/0x0003: X1
 27140/0x0004: Y1
 27141/0x0005: X2
 27142/0x0006: Y2
 27143/0x0007: X3
 27144/0x0008: Y3
 27145/0x0009: P_Vorzugalage_KanalA
 ...
 27168/0x0020: PD_RampeBitsHanbedienung
 27169/0x0021: PD_rampenBitsSchalten
 27170/0x0022: P_RBSpezRampe(3) / P_RBValSwitchOff(4) / P_RelDimAusschaltenMoeglich(5) / P_RBValSwitchOn(6) / P_RelDimEinschaltenMoeglich(7)
 27171/0x0023: P_RBSpezRampe(3) / P_WertAusschaltenMoeglich(4) / P_RBRelSwitchOff(5) / P_WertEinschaltenMoeglich(6) / P_RBRelSwitchOn(7)
 27172/0x0024: PD_RampeBitsZusatz
 27173/0x0025: PD_RampeSpezial
 ...
 27185/0x0031: P_RelDimmgrenzeUntere
 27186/0x0032: P_RelDimmgrenzeObere
 27187/0x0033: P_WertDimmgrenzeUntere
 27188/0x0034: P_WertDimmgrenzeObere
 ...
 27200/0x0040: P_Zusatzfunktion
 ...
 27203/0x0043: P_EinschaltDimmrampe (16bit)
 ...
 27205/0x0045: P_AusschaltDimmrampe (16bit)
 ...
 27207/0x0047: P_relDimmenDimmzeit (16bit)
 ...
 27209/0x0049: P_WertDimmZeit (16bit)
 ...
 27217/0x0051: P_Rueckmeldung
 27218/0x0052: P_RueckmInv
 27219/0x0053: P_StatusSendenSchalten
 27220/0x0054: P_StatusWert
 27221/0x0055: P_StatusSendenWert
 ...
 27224/0x0058: P_VerhBW
 ...
 27231/0x005f: P_PrioritaetFreigeben
 27232/0x0060: P_VerhPrioritaet
 27233/0x0061: P_Prior_BSW
 ...
 27238/0x0066: P_Einschalthelligkeit
 ...
 27246/0x006e: P_PresetfunktionFreigeben
 27247/0x006f: P_SzenenPresetsUeberschr
 27248/0x0070: P_Preset_2_FunktionEIN
 27249/0x0071: P_Preset_1_FunktionAUS
 ...
 27251/0x0073: P_PresetDimmrampe_dimmen (16bit)
 27253/0x0075: P_Preset_12_SpeichernInitialisieren
 ...
 27259/0x007b: P_Preset_4_FunktionEIN
 27260/0x007c: P_Preset_3_FunktionAUS
 ...
 27262/0x007e: P_PresetDimmrampe_dimmen (16bit)
 27264/0x0080: P_Preset_34_SpeichernInitialisieren
 ...
 27270/0x0086: P_SperrfunktionFreigeben
 ...
 27276/0x008c: P_SzenenFreigeben
 27277/0x008d: SzeneDownloadNichtÜberschreiben
 27278/0x008e: SzeneBUSNichtÜberschreiben
 27279/0x008f: P_SzeneFleALichtszene1
 27280/0x0090: P_SzeneVoreinst1
 27281/0x0091: P_SzeneUebergangszeit1 (16bit)
 27283/0x0093: P_SzeneFleALichtszene2
 27284/0x0094: P_SzeneVoreinst2
 27285/0x0095: P_SzeneUebergangszeit2 (16bit)
 27287/0x0097: P_SzeneFleALichtszene3
 27288/0x0098: P_SzeneVoreinst3
 27289/0x0099: P_SzeneUebergangszeit3 (16bit)
 27291/0x009b: P_SzeneFleALichtszene 4
 27292/0x009c: P_SzeneVoreinst 4
 27293/0x009d: P_SzeneUebergangszeit 4 (16bit)
 27295/0x009f: P_SzeneFleALichtszene 5
 27296/0x00a0: P_SzeneVoreinst 5
 27297/0x00a1: P_SzeneUebergangszeit 5 (16bit)
 27300/0x00a3: P_SzeneFleALichtszene 6
 27301/0x00a4: P_SzeneVoreinst 6
 27302/0x00a5: P_SzeneUebergangszeit 6 (16bit)
 27303/0x00a7: P_SzeneFleALichtszene 7
 27304/0x00a8: P_SzeneVoreinst 7
 27305/0x00a9: P_SzeneUebergangszeit 7 (16bit)
 27307/0x00ab: P_SzeneFleALichtszene 8
 27308/0x00ac: P_SzeneVoreinst 8
 27309/0x00ad: P_SzeneUebergangszeit 8 (16bit)
 27311/0x00af: P_SzeneFleALichtszene 9
 27312/0x00b0: P_SzeneVoreinst 9
 27313/0x00b1: P_SzeneUebergangszeit 9 (16bit)
 27315/0x00b3: P_SzeneFleALichtszene 10
 27316/0x00b4: P_SzeneVoreinst 10
 27317/0x00b5: P_SzeneUebergangszeit 10 (16bit)
 27319/0x00b7: P_SzeneFleALichtszene 11
 27320/0x00b8: P_SzeneVoreinst 11
 27321/0x00b9: P_SzeneUebergangszeit 11 (16bit)
 27323/0x00bb: P_SzeneFleALichtszene 12
 27324/0x00bc: P_SzeneVoreinst 12
 27325/0x00bd: P_SzeneUebergangszeit 12 (16bit)
 27327/0x00bf: P_SzeneFleALichtszene 13
 27328/0x00c0: P_SzeneVoreinst 13
 27329/0x00c1: P_SzeneUebergangszeit 13 (16bit)
 27331/0x00c3: P_SzeneFleALichtszene 14
 27332/0x00c4: P_SzeneVoreinst 14
 27333/0x00c5: P_SzeneUebergangszeit 14 (16bit)
 27335/0x00c7: P_SzeneFleALichtszene 15
 27336/0x00c8: P_SzeneVoreinst 15
 27337/0x00c9: P_SzeneUebergangszeit 15 (16bit)
 27339/0x00cb: P_SzeneFleALichtszene 16
 27340/0x00cc: P_SzeneVoreinst 16
 27341/0x00cd: P_SzeneUebergangszeit 16 (16bit)
 27343/0x00cf: P_SzeneFleALichtszene 17
 27344/0x00d0: P_SzeneVoreinst 17
 27345/0x00d1: P_SzeneUebergangszeit 17 (16bit)
 27347/0x00d3: P_SzeneFleALichtszene 18
 27348/0x00d4: P_SzeneVoreinst 18
 27349/0x00d5: P_SzeneUebergangszeit 18 (16bit)
...
 27360/0x00e0: P_SlaveVerhVSW
 27361/0x00e1: P_TreppeHelligkeit / P_SlaveVerhEinschalttelegr
 27362/0x00e2: P_TreppeZeitdauer_3min (16bit) / P_SlaveVerhDimmen
 27363/0x00e3: P_SlaveVerhPreset
 27364/0x00e4: P_TreppeHelligkeitDauerEIN
 27365/0x00e5: P_TreppeEndeDauerEIN
 27366/0x00e6: P_TreppeAbdimmzeit (16bit)
 27368/0x00e8: P_TreppeWarnung
 27369/0x00e9: P_TreppeVerhAusschalttelegramm
 27370/0x00ea: P_TreppeZeitAddierbar
 ...
 27372/0x00ec: P_TreppeHelligkeitNachAbdimmen

 ComObjects:
  0: In Operation (1bit out upd)

 25 ComObjects reserved per channel beginning from 10:
 Channel A
	 10: Switch / Status (1bit in/out upd)
	 11: Status switch (1bit out upd)
	 12: Relative dimming (4bit in)
	 13: Brightness value (8bit in upd)
	 14: Status brightness value (8bit out upd)
	 15: Rel. Dimming speed 0...100% (16bit out)
	 16: Forced operation (2bit in)
	 17: Call preset 1 and 2 (1bit in)
	 18: Set preset 1 and 2 (1bit in)
	 19: Call preset 3 and 4 (1bit in)
	 20: Set preset 3 and 4 (1bit in)
	 21: 8-bit-scene (8bit in)
	 22: Restore standard scene (1bit in)
	 23: Block (1bit in)
	 24: Activate staircase function (1bit in)
	 25: Permanent ON (1bit in)
	 26: Duration of staircase lighting (16bit in/out)
	 27: Warning staircase lighting (1bit out upd)
	 34: Statusbyte (8bit out upd)

 Channel B
 	 35:...
 	 59:...

*/

#endif /* CONFIG_H_ */
