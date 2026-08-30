/*-----------------------------------------------------------------------------
 * Umicom Integration Studio Module
 * File: include/umicom/integration_studio/productisation_contribution.h
 *
 * PURPOSE:
 *   Declare this thin module's adoption of Framework-owned application
 *   experience, components, layouts and productisation evidence.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/
#ifndef UMICOM_INTEGRATION_STUDIO_PRODUCTISATION_CONTRIBUTION_H
#define UMICOM_INTEGRATION_STUDIO_PRODUCTISATION_CONTRIBUTION_H

#include "umicom/application/productisation/session.h"

#ifdef __cplusplus
extern "C" {
#endif

const UmiProductApplicationAdoption *
umi_integration_studio_productisation_contribution(void);
UmiStatus umi_integration_studio_productisation_snapshot(
    UmiProductApplicationAdoptionSnapshot *out_snapshot);
UmiStatus umi_integration_studio_product_session_init(
    UmiProductApplicationSession *out_session);

#ifdef __cplusplus
}
#endif

#endif
