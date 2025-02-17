/*
   Copyright (C) 2004 - 2018 Université de Versailles Saint-Quentin-en-Yvelines (UVSQ)

   This file is part of MAQAO.

  MAQAO is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation; either version 3
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

/* Declares functions used only by the ptrace-based sampling engine */

#ifndef __SAMPLING_ENGINE_PTRACE_H__
#define __SAMPLING_ENGINE_PTRACE_H__

#include "sampling_engine_shared.h" // smpl_context_t

// Enables/disables all events groups (for all threads)
void enable_all_threads  (void **UG_data);
void disable_all_threads (void **UG_data);

/* Collects samples using ptrace (instead of perf-events inherit mode) to track processes/threads forks/exits
 * \param global_context sampling context
 * \param nprocs number of CPUs to collect, used only for pre-allocating resources
 * \param sync boolean true (resp. false) for synchronous (resp. async.) processing of forks/exits
 * \param finalize_signal Signal used by some parallel launchers to notify ranks finalization */
int tracer_new (smpl_context_t *const context, unsigned nprocs,
                boolean_t sync, int finalize_signal);

#endif // __SAMPLING_ENGINE_PTRACE_H__
