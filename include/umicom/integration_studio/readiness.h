/*-----------------------------------------------------------------------------
 * Umicom Integration Studio Module
 * File: include/umicom/integration_studio/readiness.h
 *
 * PURPOSE:
 *   Expose Framework-owned readiness and ownership evidence through the thin product boundary.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/


#ifndef UMICOM_INTEGRATION_STUDIO_READINESS_H
#define UMICOM_INTEGRATION_STUDIO_READINESS_H

#include "umicom/application/runtime/readiness.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Provide the integration studio readiness report operation used by this module and its
 * client applications.
 */
UmiStatus umi_integration_studio_readiness_report(
    UmiApplicationReadinessReport *out_report);
/**
 * Provide the integration studio readiness next feature operation used by this module and
 * its client applications.
 */
const UmiExperienceFeatureDefinition *umi_integration_studio_readiness_next_feature(void);

#ifdef __cplusplus
}
#endif

#endif
