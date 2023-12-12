/**
 ******************************************************************************
 * @file           : Common_Macros.h
 * @author         : Ahmed Naeim
 * @brief          : Contains Common Macros
 ******************************************************************************
**/

#ifndef COMMON_COMMON_MACROS_H_
#define COMMON_COMMON_MACROS_H_

#define SET_BIT(Reg,Bit_Num)									(Reg |= Bit_Num)
#define CLEAR_BIT(Reg, Bit_Num)									(Reg &= ~Bit_Num)
#define TOGGLE_BIT(Reg, Bit_Num)								(Reg ^= Bit_Num)
#define READ_BIT(Reg, Bit_Num)									(Reg & Bit_Num)

#define READ_REG(REG)											((REG))
#define WRITE_REG(REG,VAL)										((REG) = (VAL))

/*
 * @brief it takes the register and apply mask then or with the new value by applying CLEARMASK technique as CLEARMASK will have the only required
 * 	bits in the register and set them with 1 then we will use NOT (~) operator to clear them with 0 then use AND (&) operator to apply these changes
 * 	to the register then finally we can use OR (|) operator for this clear-masked register with the desired value that is already masked with the only
 * 	needed bits which are set by 1 so we will make the register masked with the needed bits only and get a readable code
 * parameters: (1) REG-> the wanted register to modify
 * 			   (2) CLEARMASK-> the needed bits in the register all set with 1s
 * 			   (3) SETMASK-> the new value you want apply to this register that will focus only on the needed bits in the register as the CLEAMASK
 */
#define MODIFY_REG(REG, CLEARMASK, SETMASK)						WRITE_REG((REG) , ((READ_REG(REG) & (~(CLEARMASK))) | (SETMASK)))



#endif /* COMMON_COMMON_MACROS_H_ */
