/*
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Initial Developer of the Original Code is Devexperts LLC.
 * Portions created by the Initial Developer are Copyright (C) 2010
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 */

#ifndef SUBSCRIPTIONS_H_INCLUDED
#define SUBSCRIPTIONS_H_INCLUDED

#include "PrimitiveTypes.h"
#include "EventData.h"
#include "DXTypes.h"

/* -------------------------------------------------------------------------- */
/*
*	Subscription defines
*/
/* -------------------------------------------------------------------------- */

#define DX_SUBSCR_FLAG_SINGLE_RECORD            0x1
//use with DX_SUBSCR_FLAG_SINGLE_RECORD flag and for dx_eid_order (Order) event
#define DX_SUBSCR_FLAG_SR_MARKET_MAKER_ORDER    0x2

extern const dxf_subscription_t dx_invalid_subscription;

/* -------------------------------------------------------------------------- */
/*
 *	Subscription types
 */
/* -------------------------------------------------------------------------- */

typedef bool (*dx_subscription_processor_t) (dxf_connection_t connection, 
                                             dx_order_source_array_ptr_t order_source,
                                             dxf_const_string_t* symbols, int symbol_count, 
                                             int event_types, dxf_uint_t subscr_flags);

/* -------------------------------------------------------------------------- */
/*
 *	Subscription functions
 */
/* -------------------------------------------------------------------------- */

/* returns dx_invalid_subscription on error */
dxf_subscription_t dx_create_event_subscription (dxf_connection_t connection, int event_types, 
                                                 dxf_uint_t subscr_flags); 
bool dx_close_event_subscription (dxf_subscription_t subscr_id);
bool dx_add_symbols (dxf_subscription_t subscr_id, dxf_const_string_t* symbols, int symbol_count);
bool dx_remove_symbols (dxf_subscription_t subscr_id, dxf_const_string_t* symbols, int symbol_count);
bool dx_add_listener (dxf_subscription_t subscr_id, dxf_event_listener_t listener, void* user_data);
bool dx_remove_listener (dxf_subscription_t subscr_id, dxf_event_listener_t listener);
bool dx_get_subscription_connection (dxf_subscription_t subscr_id, OUT dxf_connection_t* connection);
bool dx_get_event_subscription_event_types (dxf_subscription_t subscr_id, OUT int* event_types);
bool dx_get_event_subscription_symbols (dxf_subscription_t subscr_id,
                                        OUT dxf_const_string_t** symbols, OUT int* symbol_count);
bool dx_get_event_subscription_flags(dxf_subscription_t subscr_id, OUT dxf_uint_t* subscr_flags);
bool dx_process_event_data (dxf_connection_t connection,
                            dx_event_id_t event_id, dxf_const_string_t symbol_name, dxf_int_t symbol_cipher,
                            dxf_event_flags_t flags, const dxf_event_data_t data, int data_count);
bool dx_get_last_symbol_event (dxf_connection_t connection, dxf_const_string_t symbol_name, int event_type,
                               OUT dxf_event_data_t* event_data);

bool dx_process_connection_subscriptions (dxf_connection_t connection, dx_subscription_processor_t processor);


/* Functions for working with order source */
bool dx_add_order_source(dxf_subscription_t subscr_id, dxf_const_string_t source);
void dx_clear_order_source(dxf_subscription_t subscr_id);
dx_order_source_array_ptr_t dx_get_order_source(dxf_subscription_t subscr_id);

//TODO: move to DXAlgorithms?
dxf_int_t dx_symbol_name_hasher(dxf_const_string_t symbol_name);

#endif /* SUBSCRIPTIONS_H_INCLUDED */