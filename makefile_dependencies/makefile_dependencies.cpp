// --------------------------------------------------------------------------
// Name: Parth Dadhania
// SID: 1722612
// CCID: pdadhani
// AnonID: 1000330704
// CMPUT 275, Winter 2023
// Assessment: Weekly Exercise #7: Interview Question (Makefile Dependencies)
// --------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
	Description: Function to recursively build targets based on makefile dependencies. This function implements the Depth-First-Search
				 Algorithm (DFS) to traverse the interdependent targets and their dependencies.

	Arguments:
		target (string): The target to build
		makefile (unordered_map<string, vector<string>>&): The makefile data containing targets and their dependencies in a map
		built (unordered_set<string>&): The set of targets that have been built
		result (vector<string>&): The vector to store the built targets in the correct order

	Returns: This function doesn't return anything.
*/
void buildTargets(string target, unordered_map<string, vector<string>> &makefile, unordered_set<string> &built, vector<string> &result)
{
	if (built.count(target) == 0)
	{
		// Target not built yet
		for (auto dependency : makefile[target])
		{
			// Recursively build dependencies if dependency is a target
			if (makefile.count(dependency) > 0)
			{
				buildTargets(dependency, makefile, built, result);
			}
		}

		result.push_back(target); // Append target to result vector after building it
		built.insert(target);	  // Update built set
	}
	else
	{
		// Target already built, return
		return;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	unordered_map<string, vector<string>> makefile; // Store makefile data
	unordered_set<string> built;					// Store built targets

	// Read makefile data
	for (int i = 0; i < n; i++)
	{
		int k;
		string target;
		cin >> k >> target;
		target.pop_back(); // Remove trailing colon from the target

		// Store the targets and their dependencies in the unordered map
		vector<string> dependencies(k);
		for (int j = 0; j < k; j++)
		{
			cin >> dependencies[j];
		}
		makefile[target] = dependencies;
	}

	// Process make commands
	for (int i = 0; i < m; i++)
	{
		string cmd, target;
		cin >> cmd >> target;

		vector<string> result;
		buildTargets(target, makefile, built, result); // Call function to build current targets

		// Output the built targets
		if (result.empty())
		{
			// Output message if the target already built
			cout << "make: `" << target << "' is up to date.";
		}
		else
		{
			// Output the built targets in order of their building
			for (size_t i = 0; i < result.size(); i++)
			{
				if (i == result.size() - 1)
				{
					cout << result[i];
				}
				else
				{
					cout << result[i] << " ";
				}
			}
		}
		cout << endl;
	}

	return 0;
}