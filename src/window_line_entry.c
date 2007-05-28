#include <assert.h>

#include "board.h"
#include "bridge.h"
#include "file.h"
#include "interface.h"
#include "support.h"
#include "window_card.h"

GtkWidget *window_line_entry = NULL;

void board_set_from_line_entry(board *b)
{
	assert (window_line_entry);
	GtkEntry *line_entry = GTK_ENTRY(lookup_widget(window_line_entry, "line_entry"));
	const char *line = gtk_entry_get_text(line_entry);
	board_clear(b);
	if (!board_parse_line(line, b, ' ', '.')) {
		board_statusbar(b->win, "Parse error");
	}
	card_window_update(b->dealt_cards);
	show_board(b);
}

void line_entry_set_from_board(board *b)
{
	if (!window_line_entry)
		return;

	GtkEntry *line_entry = GTK_ENTRY(lookup_widget(window_line_entry, "line_entry"));
	GString *line = board_format_line(b, ' ', '.');
	gtk_entry_set_text(line_entry, line->str);
	g_string_free(line, TRUE);
}

void window_line_entry_init(board *b)
{
	if (!window_line_entry) {
		window_line_entry = create_window_line_entry ();
		gtk_widget_show (window_line_entry);
	}
	if (b)
		line_entry_set_from_board(b);
}
