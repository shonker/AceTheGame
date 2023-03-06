#pragma once
#include "ace_type.hpp"
#include "cheat_cmd_handler.hpp"
#include "input.hpp"
#include "maps.hpp"
#include "scanner.hpp"

#include <string>
#include <vector>

template <typename T> struct engine_module {
  ACE_scanner<T> *scanner_ptr;
  freezer<T> *freezer_ptr;
  proc_rw<T> *process_rw;
};

template <typename T>
E_loop_statement
cheater_mode_on_each_input(int pid, engine_module<T> engine_module,
                           struct cheat_mode_config *cheat_config,
                           std::string input_str);

template <typename T>
void cheater_mode_loop(int pid, engine_module<T> engine_module);

template <typename T>
E_loop_statement cheater_on_line(engine_module<T> engine_module,
                                 cheat_mode_config *cheat_config,
                                 std::string input_str);

/*
 * mode to scan and write to all segments of process in [segments_to_scan]
 * from and to the  process with pid of [pid]
 *
 * [num_type]: number type to scan and write from and to the process
 * */
void cheater_mode(int pid, E_num_type num_type);