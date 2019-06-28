/* libmsr_error.c
 *
 * Copyright (c) 2011-2016, Lawrence Livermore National Security, LLC.
 * LLNL-CODE-645430
 *
 * Produced at Lawrence Livermore National Laboratory
 * Written by  Barry Rountree, rountree@llnl.gov
 *             Scott Walker,   walker91@llnl.gov
 *             Kathleen Shoga, shoga1@llnl.gov
 *
 * All rights reserved.
 *
 * This file is part of libmsr.
 *
 * libmsr is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * libmsr is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libmsr. If not, see <http://www.gnu.org/licenses/>.
 *
 * This material is based upon work supported by the U.S. Department of
 * Energy's Lawrence Livermore National Laboratory. Office of Science, under
 * Award number DE-AC52-07NA27344.
 *
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libmsr_error.h"

void libmsr_error_message(int err, char *msg, size_t size)
{
    switch (err)
    {
        case LIBMSR_ERROR_PLATFORM_NOT_SUPPORTED:
            strncpy(msg, "<libmsr> Feature not supported on this architecture", size);
            break;
        case LIBMSR_ERROR_ARRAY_BOUNDS:
            strncpy(msg, "<libmsr> Accessing element outside allocated bounds", size);
            break;
        case LIBMSR_ERROR_MSR_BATCH:
            strncpy(msg, "<libmsr> Could not perform MSR batch operation", size);
            break;
        case LIBMSR_ERROR_PLATFORM_ENV:
            strncpy(msg, "<libmsr> Invalid or incorrect architecture configuration", size);
            break;
        case LIBMSR_ERROR_MSR_MODULE:
            strncpy(msg, "<libmsr> Could not locate MSR device", size);
            break;
        case LIBMSR_ERROR_MSR_OPEN:
            strncpy(msg, "<libmsr> Could not open MSR device", size);
            break;
        case LIBMSR_ERROR_MSR_CLOSE:
            strncpy(msg, "<libmsr> Could not close MSR device", size);
            break;
        case LIBMSR_ERROR_MSR_READ:
            strncpy(msg, "<libmsr> Could not read MSR device", size);
            break;
        case LIBMSR_ERROR_MSR_WRITE:
            strncpy(msg, "<libmsr> Could not write MSR device", size);
            break;
        case LIBMSR_ERROR_RUNTIME:
            strncpy(msg, "<libmsr> Runtime error", size);
            break;
        case LIBMSR_ERROR_RAPL_INIT:
            strncpy(msg, "<libmsr> Could not initialize RAPL", size);
            break;
        case LIBMSR_ERROR_MSR_INIT:
            strncpy(msg, "<libmsr> Could not initialize MSR", size);
            break;
        case LIBMSR_ERROR_INVAL:
            strncpy(msg, "<libmsr> Invalid value", size);
            break;
        case LIBMSR_ERROR_NOT_IMPLEMENTED_YET:
            strncpy(msg, "<libmsr> This has not yet been implemented by libmsr", size);
            break;
        case LIBMSR_ERROR_MEMORY_ALLOCATION:
            strncpy(msg, "<libmsr> Could not allocate memory", size);
            break;
        case LIBMSR_ERROR_CSR_INIT:
            strncpy(msg, "<libmsr> Could not initialize CSR", size);
            break;
        case LIBMSR_ERROR_CSR_COUNTERS:
            strncpy(msg, "<libmsr> CSR performance counter error.", size);
            break;
        default:
            strncpy(msg, "<libmsr> Undefined error code", size);
            break;
    }
    if (size > 0)
    {
        msg[size-1] = '\0';
    }
}

char *get_libmsr_error_message(int err)
{
    char *brief_msg = (char *) malloc(NAME_MAX * sizeof(char));
    if (err)
    {
        err = err;
    }
    else
    {
        err = LIBMSR_ERROR_RUNTIME;
    }
    libmsr_error_message(err, brief_msg, NAME_MAX);
    return brief_msg;
}

void libmsr_error_handler(const char *desc, int err, const char *host, const char *filename, int line)
{
    fprintf(stderr, "Error: %s: %s: %s:%s::%d\n", get_libmsr_error_message(err), desc, host, filename, line);
}
