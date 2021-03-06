/* filter_filess.h
 * Declarations of routines for reading and writing the filters file.
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * SPDX-License-Identifier: GPL-2.0+*/

#ifndef __UI_FILTERS_H__
#define __UI_FILTERS_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * Filter lists.
 */
typedef enum {
  CFILTER_LIST,        /* capture filter list - saved */
  DFILTER_LIST,        /* display filter list - saved */
  CFILTER_EDITED_LIST, /* capture filter list - currently edited. GTK+ only. */
  DFILTER_EDITED_LIST  /* display filter list - currently edited. GTK+ only. */
} filter_list_type_t;

/*
 * Item in a list of filters.
 */
typedef struct {
  char *name;          /* filter name */
  char *strval;        /* filter expression */
} filter_def;

/*
 * Read in a list of filters.
 *
 * On error, report the error via the UI.
 */
void read_filter_list(filter_list_type_t list_type);

/*
 * Get a pointer to the first entry in a filter list.
 */
GList *get_filter_list_first(filter_list_type_t list);

/*
 * Add a new filter to the end of a list.
 * Returns a pointer to the newly-added entry.
 */
GList *add_to_filter_list(filter_list_type_t list, const char *name,
                          const char *expression);

/*
 * Remove a filter from a list.
 */
void remove_from_filter_list(filter_list_type_t list, GList *fl_entry);

/*
 * Write out a list of filters.
 *
 * On error, report the error via the UI.
 */
void save_filter_list(filter_list_type_t list_type);

/*
 * Clone the filter list so it can be edited. GTK+ only.
 */
void copy_filter_list(filter_list_type_t dest_type, filter_list_type_t src_type);

/*
 * Free all filter lists
 */
void free_filter_lists(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __UI_FILTERS_H__ */

/*
 * Editor modelines  -  http://www.wireshark.org/tools/modelines.html
 *
 * Local Variables:
 * c-basic-offset: 2
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * vi: set shiftwidth=2 tabstop=8 expandtab:
 * :indentSize=2:tabSize=8:noTabs=true:
 */
