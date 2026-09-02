/*-----------------------------------------------------------------------------
 * Umicom Integration Studio Module
 * File: include/umicom/integration_studio/workspace_commands.h
 *
 * PURPOSE:
 *   Expose product-facing layout, panel and context commands implemented by the Framework runtime.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/


#ifndef UMICOM_INTEGRATION_STUDIO_WORKSPACE_COMMANDS_H
#define UMICOM_INTEGRATION_STUDIO_WORKSPACE_COMMANDS_H

#include "umicom/integration_studio/runtime.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Provide the integration studio workspace select layout operation used by this module and
 * its client applications.
 */
UmiStatus umi_integration_studio_workspace_select_layout(
    UmiApplicationWorkspaceRuntime *runtime,
    const char *layout_id);
/**
 * Provide the integration studio workspace activate panel operation used by this module
 * and its client applications.
 */
UmiStatus umi_integration_studio_workspace_activate_panel(
    UmiApplicationWorkspaceRuntime *runtime,
    const char *panel_id);
/**
 * Provide the integration studio workspace set context operation used by this module and
 * its client applications.
 */
UmiStatus umi_integration_studio_workspace_set_context(
    UmiApplicationWorkspaceRuntime *runtime,
    const char *group_id,
    const char *value);
/**
 * Provide the integration studio workspace commands operation used by this module and its
 * client applications.
 */
const UmiApplicationCommandSurface *umi_integration_studio_workspace_commands(
    const UmiApplicationWorkspaceRuntime *runtime);

#ifdef __cplusplus
}
#endif

#endif
