/*-----------------------------------------------------------------------------
 * Umicom Integration Studio Module
 * File: include/umicom/integration_studio/workspace.h
 *
 * PURPOSE:
 *   Expose product workspace lookups without duplicating Framework workbench or layout logic.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/

#ifndef UMICOM_INTEGRATION_STUDIO_WORKSPACE_H
#define UMICOM_INTEGRATION_STUDIO_WORKSPACE_H

#include <stddef.h>

#include "umicom/application/experience.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Return the number of records represented by integration studio workspace layout without
 * changing their state.
 */
size_t umi_integration_studio_workspace_layout_count(void);

/**
 * Find integration studio workspace layout while leaving the underlying catalogue or model
 * owned by this module.
 */
const UmiExperienceLayoutDefinition *umi_integration_studio_workspace_layout_at(
    size_t index);

/**
 * Provide the integration studio workspace default operation used by this module and its
 * client applications.
 */
const UmiExperienceLayoutDefinition *umi_integration_studio_workspace_default(void);

/**
 * Provide the integration studio workspace next feature operation used by this module and
 * its client applications.
 */
const UmiExperienceFeatureDefinition *umi_integration_studio_workspace_next_feature(
    void);

#ifdef __cplusplus
}
#endif

#endif
