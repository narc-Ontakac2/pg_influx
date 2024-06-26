/*
 * Copyright 2022 Timescale Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WORKER_H_
#define WORKER_H_

#include <postgres.h>

#include <postmaster/bgworker.h>

#define INFLUX_LIBRARY_NAME "influx"
#define INFLUX_FUNCTION_NAME "InfluxWorkerMain"

typedef struct WorkerArgs {
  char role[32];
  char namespace[32];
  char database[32];
  char service[32];
} WorkerArgs;

void InfluxWorkerInit(BackgroundWorker *worker, WorkerArgs *args);

void PGDLLEXPORT InfluxWorkerMain(Datum dbid) pg_attribute_noreturn();

#endif /* WORKER_H_ */
