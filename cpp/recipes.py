from collections import defaultdict, deque


class Sol:
    def findAllRecipes(self, recipes: list[str],
                       ingredients: list[str],
                       supplies: list[str]
                       ) -> list[str]:
        
        in_Degree = {}
        g = defaultdict(list)

        for recipe, components in zip(recipes, ingredients):
            in_Degree[recipe] = len(components)

            for component in components:
                g[component].append(recipe)


        q = deque()

        rez = []

        while q:
            supply = q.popleft()
            for recipe in g[supply]:
                in_Degree[recipe] -= 1
                if in_Degree[recipe] == 0:
                    q.append(recipe)
                    rez.append(recipe)



        return []




def main():
    s = Sol()


if __name__ == '__main__':
    main()
