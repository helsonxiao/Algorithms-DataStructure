states_needed = set(["mt", "wa", "or", "id" ,"nv", "ut", "ca", "az"])

stations = {}
stations["kone"] = set(["id", "nv", "ut"])
stations["ktwo"] = set(["wa", "id", "mt"])
stations["kthree"] = set(["or", "nv", "ca"])
stations["kfour"] = set(["nv", "ut"])
stations["kfive"] = set(["ca", "az"])

final_stations = set()


# Version 2.0
# states_covered = set()
# while len(states_covered) != len(states_needed):
# 	best_station = None
# 	max_covered_count = 0
# 	for station, states_set in stations.items():
# 		new_states_covered = states_covered | states_set
# 		new_covered_count = len(new_states_covered)
# 		if new_covered_count > max_covered_count:
# 			max_covered_count = new_covered_count
# 			best_station = station

# 	states_covered = states_covered | stations[best_station]
# 	final_stations = final_stations | set([best_station])


# Reference Answer
while states_needed:
	best_station = None
	states_covered = set()
	for station, states in stations.items():
		covered = states & states_needed
		if len(covered) > len(states_covered):
			states_covered = covered
			best_station = station

	states_needed -= states_covered
	final_stations.add(best_station)

print final_stations # set(['ktwo', 'kthree', 'kone', 'kfive'])

