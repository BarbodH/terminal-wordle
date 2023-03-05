#include <stdio.h>

#include "yorkle.h"

int main(void) {

  valid_word_list_t valid_words;
  player_stats_t stats;
  char todays_answer[WORD_SIZE + 2];

  char current_attempt[WORD_SIZE + 2];
  letter_result_t attempt_result[WORD_SIZE];
  unsigned int attempt;
  
  if (!load_valid_words(&valid_words)) {
    perror("Error retrieving list of valid words");
    return 1;
  }
  if (!load_todays_answer(todays_answer)) {
    perror("Error retrieving today's answer");
    return 1;
  }

  load_stats(&stats);
  print_stats(&stats);

  for (attempt = 1; attempt <= MAX_NUM_ATTEMPTS; attempt++) {

    do {
      if (!read_attempt(attempt, current_attempt))
        return 2;
    } while (!attempt_is_valid(&valid_words, current_attempt));

    int correct = compare_result(todays_answer, current_attempt, attempt_result);
    print_attempt_result(current_attempt, attempt_result);
    if (correct) break;
  }

  printf("Correct word is: %s\n\n", todays_answer);

  if (!save_stats(&stats, attempt)) {
    perror("Error saving stats");
    return 1;
  }

  print_stats(&stats);

  return 0;
}
