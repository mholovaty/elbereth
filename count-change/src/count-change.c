/*
 ============================================================================
 Name        : count-change.c
 Author      : Mikhail Golovatyi
 Version     :
 Copyright   : GPLv3
 Description : Count change combinations for a given amount.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <glib.h>


int first_denomination(int kinds_of_coins) {
	switch (kinds_of_coins) {
	case 1:
		return 1;
	case 2:
		return 5;
	case 3:
		return 10;
	case 4:
		return 25;
	case 5:
		return 50;
	}
}

int cc_key(int amount, int kinds_of_coins) {
	return amount * 4 + kinds_of_coins - 1;
}


int cc(int amount, int kinds_of_coins, GHashTable* tab) {
	if (amount == 0) {
		return 1;
	};
	if (amount < 0) {
		return 0;
	};
	if (kinds_of_coins == 0) {
		return 0;
	};

	int cc_value;

/*	cc_value =
			cc(amount, kinds_of_coins - 1, tab) +
			cc(amount - first_denomination(kinds_of_coins), kinds_of_coins, tab);
*/
	int key = cc_key(amount, kinds_of_coins);

	gpointer cc_pointer = g_hash_table_lookup(tab, &key);

	if (cc_pointer) {
		cc_value =  GPOINTER_TO_INT(cc_pointer);
	} else {
		cc_value =
				cc(amount, kinds_of_coins - 1, tab) +
				cc(amount - first_denomination(kinds_of_coins), kinds_of_coins, tab);

		g_hash_table_insert(tab, &key, GINT_TO_POINTER(cc_value));
	};

	return cc_value;
}

int count_change(int amount) {
	GHashTable* tab = g_hash_table_new(g_int_hash, g_int_equal);
	return cc(amount, 5, tab);
}

int main(int argc, char *argv[]) {

	if (argc != 2) {
		printf("Usage: %s AMOUNT\n", argv[0]);

		return EXIT_FAILURE;
	} else {
		int amount = atoi(argv[1]);

		int combinations = count_change(amount);

		printf("Ka-ching! %d\n", combinations);

		return EXIT_SUCCESS;
	}
}
