/** @file Data.cpp
 * 
 * @author	Marek Kopicki
 *
 * @copyright  Copyright (C) 2015 Marek Kopicki, University of Birmingham, UK
 *
 * @license  This file copy is licensed to you under the terms described in
 *           the License.txt file included in this distribution.
 *
 */

#include <Golem/Ctrl/SingleCtrl/Data.h>
#include <Golem/Ctrl/PISA/Data.h>
#include <Golem/Ctrl/Data.h>
#include <Golem/Sys/XMLData.h>

//------------------------------------------------------------------------------

using namespace golem;

//------------------------------------------------------------------------------

void golem::XMLData(PISASoftHand::Desc &val, XMLContext* context, bool create) {
	ASSERT(context)
	XMLData((SingleCtrl::Desc&)val, context, create);
	XMLData(val.synergy, "c", context->getContextFirst("synergy"), create);
}

//------------------------------------------------------------------------------
