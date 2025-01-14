/*
 * Copyright (c) 2016 Jean-Paul Etienne <fractalclone@gmail.com>
 * Copyright (c) 2018 Foundries.io Ltd
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief RISCV32 public exception handling
 *
 * RISCV32-specific kernel exception handling interface.
 */

#ifndef ZEPHYR_INCLUDE_ARCH_RISCV32_EXP_H_
#define ZEPHYR_INCLUDE_ARCH_RISCV32_EXP_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _ASMLANGUAGE
#include <zephyr/types.h>
#include <toolchain.h>

#ifdef CONFIG_RISCV_SOC_CONTEXT_SAVE
#include <soc_context.h>
#endif

/*
 * The name of the structure which contains soc-specific state, if
 * any, as well as the soc_esf_t typedef below, are part of the RISC-V
 * arch API.
 *
 * The contents of the struct are provided by a SOC-specific
 * definition in soc_context.h.
 */
#ifdef CONFIG_RISCV_SOC_CONTEXT_SAVE
struct soc_esf {
	SOC_ESF_MEMBERS;
};
#endif

struct __esf {
	u32_t ra;       /* return address */
	u32_t gp;       /* global pointer */
	u32_t tp;       /* thread pointer */

	u32_t t0;       /* Caller-saved temporary register */
	u32_t t1;       /* Caller-saved temporary register */
	u32_t t2;       /* Caller-saved temporary register */
	u32_t t3;       /* Caller-saved temporary register */
	u32_t t4;       /* Caller-saved temporary register */
	u32_t t5;       /* Caller-saved temporary register */
	u32_t t6;       /* Caller-saved temporary register */

	u32_t a0;       /* function argument/return value */
	u32_t a1;       /* function argument */
	u32_t a2;       /* function argument */
	u32_t a3;       /* function argument */
	u32_t a4;       /* function argument */
	u32_t a5;       /* function argument */
	u32_t a6;       /* function argument */
	u32_t a7;       /* function argument */

	u32_t mepc;      /* machine exception program counter */
	u32_t mstatus;   /* machine status register */

#ifdef CONFIG_RISCV_SOC_CONTEXT_SAVE
	struct soc_esf soc_context;
#endif
};

typedef struct __esf z_arch_esf_t;
#ifdef CONFIG_RISCV_SOC_CONTEXT_SAVE
typedef struct soc_esf soc_esf_t;
#endif
#endif /* _ASMLANGUAGE */

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_ARCH_RISCV32_EXP_H_ */
