/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

/**
* @brief returns true when reach last entry in flight table
* @return True when is the last entre of the flight table, False otherwise
*/

static bool is_last_line(unsigned int hour, unsigned int type) {
  return  hour == HOURS - 1u && type == TYPE - 1u;
}

void array_dump(DeliveryTable a) {
  for (unsigned int type = 0u; type < TYPE; ++type) {
    for (unsigned int hour = 0u; hour < HOURS; ++hour) {
      Flight f = a[type][hour];
      fprintf(stdout, "%c: flight with %u %s arrived at %u:00", f.code, f.items_amount, f.type == 0 ? "boxes" : "letters", f.hour - 1);
      if (!is_last_line(hour, type))
      {
        fprintf(stdout, "\n");
      }
    }
  }
}


//unsigned int extra_space_fee_cost (DeliveryTable a) {
  /* COMPLETAR */
//  return 0;
//  }



void array_from_file(DeliveryTable array, const char *filepath) {
  FILE *file = NULL;

  file = fopen(filepath, "r");
  if (file == NULL) {
    fprintf(stderr, "File does not exist.\n");
    exit(EXIT_FAILURE);
  }

  char code;
  int i=0;
  int hora_caja,numero_caja, hora_carta, numero_carta;
  while (feof(file) == 0) {
    int res = fscanf(file, " _%c_ ", &code);
    int resp = fscanf(file, "%d %d %d %d\n", &hora_caja, &numero_caja, &hora_carta, &numero_carta);
    if (res != 1 && resp != 5) {
      fprintf(stderr, "Invalid file.\n");
      exit(EXIT_FAILURE);
    }
    
    
    Flight flight_boxes;
    flight_boxes.code = code;
    flight_boxes.type = 0;
    flight_boxes.hour = hora_caja;
    flight_boxes.items_amount = numero_caja;

    
    Flight flight_letters;
    flight_letters.code = code;
    flight_letters.type = 1;
    flight_letters.hour = hora_carta;
    flight_letters.items_amount = numero_carta;
    
    array[flight_letters.type][i] = flight_letters;
    array[flight_boxes.type][i] = flight_boxes;
    i++;
    fclose(file);
  }
}
