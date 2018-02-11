# initialize graph hash table
graph = {}

graph["start"] = {}
graph["start"]["a"] = 6
graph["start"]["b"] = 2

graph["a"] = {}
graph["a"]["fin"] = 1

graph["b"] = {}
graph["b"]["a"] = 3
graph["b"]["fin"] = 5

graph["fin"] = {} # node fin doesn't have children(neighbor)


# initialize costs hash table
# it has start_node's closest node cost
costs = {}
costs["a"] = 6
costs["b"] = 2
infinity = float('inf')
costs["fin"] = infinity


# initialize parents relationship hash table
# it contains every node's costless parent_node
parents = {}
parents["a"] = "start"
parents["b"] = "start"
parents["fin"] = None # we don't know yet


# initilize processed nodes hash table
# it'll be our final map
processed = []

def find_next_lowest_cost_node(costs):
	lowest_cost = float('inf')
	lowest_cost_node = None
	for node in costs:
		cost = costs[node]
		if node not in processed and cost < lowest_cost:
			lowest_cost = cost
			lowest_cost_node = node

	return lowest_cost_node

node = "start" # nonsense, only for understanding.
processed.append(node)

node = find_next_lowest_cost_node(costs) # processed node'll be skipped
while node is not None:
	node_neighbors = graph[node]
	cost_base = costs[node]

	for node_neighbor in node_neighbors.keys():
		new_cost = cost_base + node_neighbors[node_neighbor]
		if new_cost < costs[node_neighbor]:
			costs[node_neighbor] = new_cost
			parents[node_neighbor] = node

	processed.append(node) # we have processed all this node's neighbors
	node = find_next_lowest_cost_node(costs)

print graph # {'a': {'fin': 1}, 'start': {'a': 6, 'b': 2}, 'b': {'a': 3, 'fin': 5}, 'fin': {}}
print parents # {'a': 'b', 'b': 'start', 'fin': 'a'}
print costs # {'a': 5, 'b': 2, 'fin': 6}
print processed # ['start', 'b', 'a', 'fin']
