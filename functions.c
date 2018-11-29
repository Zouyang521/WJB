//void showTable
#include <ansi_c.h>
#include "TestCircuitWaferNew.h"
#include "functions.h"

u8 * mycheckbuff(u8 *buff,u8 buffweidth)
{
	u8 i;
	u8 *pt;
	u8 flag[2]= {""};
	u16 tmp;
	u16 tmpp;
	for(i=0; i<2; i++)flag[i]=0;

	pt = (u8 *)strchr((const char*)buff,0x7e);//DownHead
	if(pt!=NULL)
		flag[0] = 1;
	else
		return 0;




//check
	if(flag[0]==1)
	{
		tmp = GetCRC16(pt+3,*(pt+1));
		//	printf("%d",*(pt+1)+1);
		//tmpp=*(pt+1+*(pt+1)+1)<<8;
		//tmpp+=*(pt+*(pt+1)+2+1);
		tmpp=*(pt+*(pt+1)+4)<<8;
		tmpp+=*(pt+*(pt+1)+3);
		if(tmp == tmpp )
			flag[1] = 1;
	}
	else
		return 0;

	if(flag[1]==1)
		return pt;
	else
		return 0;
}
unsigned short GetCRC16(unsigned char * addr,int length)

{

	unsigned short crc;

	unsigned char da;

	unsigned short crc_ta[16]=
	{

		0x0000,0x1021,0x2042,0x3063,0x4084,0x50a5,0x60c6,0x70e7,

		0x8108,0x9129,0xa14a,0xb16b,0xc18c,0xd1ad,0xe1ce,0xf1ef
	};



	crc = 0;

	while(length--!=0)

	{

		da=((unsigned char)(crc/256))/16;

		crc <<= 4;

		crc ^= crc_ta[da^(*addr/16)];

		da = ((unsigned char)(crc/256))/16;

		crc <<= 4;

		crc ^= crc_ta[da^(*addr&0x0f)];

		addr++;

	}

	return (crc);
//	return ((crc&0x00ff)<<8)  + ((crc&0xff00)>>8) ;
}
short HexToInt(unsigned char *Hex,int i)
{

	short tempint=0;
	tempint =Hex[i];
	tempint &=0xff;
	tempint |=((long)Hex[i+1]<<8);
	/*tempint &=0xffff;
	tempint |=((long)Hex2[2]<<16);
	tempint &=0xffffff;
	tempint |=((long)Hex2[3]<<24);*/
	return tempint;

}
