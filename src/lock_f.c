/* -*- C -*-
 *
 * Copyright 2011 Sandia Corporation. Under the terms of Contract
 * DE-AC04-94AL85000 with Sandia Corporation, the U.S.  Government
 * retains certain rights in this software.
 *
 * Copyright (c) 2017 Intel Corporation. All rights reserved.
 * This software is available to you under the BSD license.
 *
 * This file is part of the Sandia OpenSHMEM software package. For license
 * information, see the LICENSE file in the top level directory of the
 * distribution.
 *
 */

#include "config.h"

#include <stdio.h>
#include <stdlib.h>

#define SHMEM_INTERNAL_INCLUDE
#include "shmem.h"
#include "shmem_internal.h"
#include "shmem_lock.h"


/* BWB: FIX ME: technically, the spec says that this interface is an
   INTEGER.  But all implementations I can find assume it's an 8 byte
   integer. */


#define FC_SHMEM_CLEAR_LOCK FC_FUNC_(shmem_clear_lock, SHMEM_CLEAR_LOCK)
void SHMEM_FUNCTION_ATTRIBUTES FC_SHMEM_CLEAR_LOCK(long *lockp);
void
FC_SHMEM_CLEAR_LOCK(long *lockp)
{
    SHMEM_ERR_CHECK_INITIALIZED();
    SHMEM_ERR_CHECK_SYMMETRIC(lockp, sizeof(long));

    shmem_internal_clear_lock(lockp);
}


#define FC_SHMEM_SET_LOCK FC_FUNC_(shmem_set_lock, SHMEM_SET_LOCK)
void SHMEM_FUNCTION_ATTRIBUTES FC_SHMEM_SET_LOCK(long *lockp);
void
FC_SHMEM_SET_LOCK(long *lockp)
{
    SHMEM_ERR_CHECK_INITIALIZED();
    SHMEM_ERR_CHECK_SYMMETRIC(lockp, sizeof(long));

    shmem_internal_set_lock(lockp);
}


#define FC_SHMEM_TEST_LOCK FC_FUNC_(shmem_test_lock, SHMEM_TEST_LOCK)
fortran_integer_t SHMEM_FUNCTION_ATTRIBUTES FC_SHMEM_TEST_LOCK(long *lockp);
fortran_integer_t
FC_SHMEM_TEST_LOCK(long *lockp)
{
    SHMEM_ERR_CHECK_INITIALIZED();
    SHMEM_ERR_CHECK_SYMMETRIC(lockp, sizeof(long));

    return shmem_internal_test_lock(lockp);
}
