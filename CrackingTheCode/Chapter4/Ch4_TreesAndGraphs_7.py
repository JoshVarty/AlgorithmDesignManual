# Build Order: You are given a list of projects and a list of dependencies (which is a list of pairsof projects where the second project is
# dependent on the first). All of a project's dependencies must be built before the project is. Find a build order that will allow the
# projects to be built. If there is no valid build order, return an error. 
# EXAMPLE
# Input:
# projects: a b c d e f
# dependencies: (a,d) (f,b) (b,d) (f,a) (d,c)
# 
# Output: f e a b d c

def buildOrder(projects, dependencies):

    #Create map from project -> dependencies
    dependencyLookup = {}

    for project in projects:
        dependencyLookup[project] = []

    for (dependency, project) in dependencies:
        dependencyLookup[project].append(dependency)

    projectBuildOrder = []

    while len(dependencyLookup) > 0:

        #Find a project with no dependencies
        projectToAdd = None
        for project, dependencies in dependencyLookup.items():
            if len(dependencies) == 0:
                projectToAdd = project
                break
        
        if projectToAdd is None:
            #There is no project without dependencies (ie. circular dependencies)
            return None
        else:
            #Add the project to the build order and remove it from the graph
            projectBuildOrder.append(projectToAdd)
            del dependencyLookup[projectToAdd]

            #Remove any dependencies on this project
            for project, dependencies in dependencyLookup.items():
                if projectToAdd in dependencies:
                    dependencies.remove(projectToAdd)

    return projectBuildOrder


projects = ['a']
dependencies = []
result = buildOrder(projects, dependencies)
assert(result == ['a'])

projects = ['a', 'b']
dependencies = [('a','b')]
result = buildOrder(projects, dependencies)
assert(result == ['a','b'])

projects = ['a', 'b']
dependencies = [('b','a')]
result = buildOrder(projects, dependencies)
assert(result == ['b','a'])

projects = ['a', 'b',]
dependencies = [('a','b'),('b','a')]
result = buildOrder(projects, dependencies)
assert(result is None)

projects = ['a', 'b','c','d','e','f']
dependencies = [('a','d'),('f','b'), ('b','d'), ('f','a'), ('d','c')]
result = buildOrder(projects, dependencies)
assert(result == ['e','f','b','a','d','c'])