/*
 * Copyright (c) 2000-2002 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 *
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */
/*
 * @OSF_COPYRIGHT@
 */
/*
 * Mach Operating System
 * Copyright (c) 1991,1990,1989,1988,1987 Carnegie Mellon University
 * All Rights Reserved.
 *
 * Permission to use, copy, modify and distribute this software and its
 * documentation is hereby granted, provided that both the copyright
 * notice and this permission notice appear in all copies of the
 * software, derivative works or modified versions, and any portions
 * thereof, and that both notices appear in supporting documentation.
 *
 * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"
 * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR
 * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.
 *
 * Carnegie Mellon requests users of this software to return to
 *
 *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU
 *  School of Computer Science
 *  Carnegie Mellon University
 *  Pittsburgh PA 15213-3890
 *
 * any improvements or extensions that they make and grant Carnegie Mellon
 * the rights to redistribute these changes.
 */
/*
 */
/*
 * File: mach/vm_prot.h
 * Author:  Avadis Tevanian, Jr., Michael Wayne Young
 *
 * Virtual memory protection definitions.
 *
 */

#ifndef  _MACH_VM_PROT_H_
#define  _MACH_VM_PROT_H_

/*
 * Types defined:
 *
 * vm_prot_t      VM protection values.
 */

typedef int    vm_prot_t;

/*
 * Protection values, defined as bits within the vm_prot_t type
 */

#define  VM_PROT_NONE   ((vm_prot_t) 0x00)

#define VM_PROT_READ ((vm_prot_t) 0x01)   /* read permission */
#define VM_PROT_WRITE   ((vm_prot_t) 0x02)   /* write permission */
#define VM_PROT_EXECUTE ((vm_prot_t) 0x04)   /* execute permission */

/*
 * The default protection for newly-created virtual memory
 */

#define VM_PROT_DEFAULT (VM_PROT_READ|VM_PROT_WRITE)

/*
 * The maximum privileges possible, for parameter checking.
 */

#define VM_PROT_ALL  (VM_PROT_READ|VM_PROT_WRITE|VM_PROT_EXECUTE)

/*
 * An invalid protection value.
 * Used only by memory_object_lock_request to indicate no change
 * to page locks.  Using -1 here is a bad idea because it
 * looks like VM_PROT_ALL and then some.
 */

#define VM_PROT_NO_CHANGE  ((vm_prot_t) 0x08)

/*
 *      When a caller finds that they cannot obtain write permission on a
 *      mapped entry, the following flag can be used.  The entry will
 *      be made "needs copy" effectively copying the object (using COW),
 *      and write permission will be added to the maximum protections
 *      for the associated entry.
 */

#define VM_PROT_COPY            ((vm_prot_t) 0x10)


/*
 * Another invalid protection value.
 * Used only by memory_object_data_request upon an object
 * which has specified a copy_call copy strategy. It is used
 * when the kernel wants a page belonging to a copy of the
 * object, and is only asking the object as a result of
 * following a shadow chain. This solves the race between pages
 * being pushed up by the memory manager and the kernel
 * walking down the shadow chain.
 */

#define VM_PROT_WANTS_COPY ((vm_prot_t) 0x10)

#ifdef PRIVATE
/*
 * The caller wants this memory region treated as if it had a valid
 * code signature.
 */

#define VM_PROT_TRUSTED    ((vm_prot_t) 0x20)
#endif /* PRIVATE */

/*
 *    Another invalid protection value.
 * Indicates that the other protection bits are to be applied as a mask
 * against the actual protection bits of the map entry.
 */
#define VM_PROT_IS_MASK    ((vm_prot_t) 0x40)

#endif   /* _MACH_VM_PROT_H_ */
