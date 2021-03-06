/** @file Load.h
 * 
 * @author	Marek Kopicki
 *
 * @copyright  Copyright (C) 2015 Marek Kopicki, University of Birmingham, UK
 *
 * @license  This file copy is licensed to you under the terms described in
 *           the License.txt file included in this distribution.
 *
 */

#pragma once
#ifndef _GOLEM_CTRL_MULTICTRL_LOAD_H_
#define _GOLEM_CTRL_MULTICTRL_LOAD_H_

//------------------------------------------------------------------------------

#include <Golem/Sys/Library.h>

//------------------------------------------------------------------------------

extern "C" {
	GOLEM_LIBRARY_DECLDIR void loadControllerDesc(void* pContext, void* pXMLContext, void* pControllerDesc);
};

//------------------------------------------------------------------------------

#endif /*_GOLEM_CTRL_MULTICTRL_LOAD_H_*/
