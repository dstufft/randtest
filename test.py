import collections
import random
import timeit
import prettytable
import _arc4random

NUM = 10000000


class UserlandRandom:

    def random(self):
        return _arc4random.arc4random_float()

deterministic = random.Random()
system = random.SystemRandom()
userland = UserlandRandom()

results = collections.OrderedDict()


results["deterministic"] = timeit.timeit(
    "deterministic.random()",
    setup="from __main__ import deterministic",
    number=NUM,
)

results["system"] = timeit.timeit(
    "system.random()",
    setup="from __main__ import system",
    number=NUM,
)

results["userland"] = timeit.timeit(
    "userland.random()",
    setup="from __main__ import userland",
    number=NUM,
)


table = prettytable.PrettyTable(["method", "usecs per call"])
table.align["method"] = "l"
table.align["usecs per call"] = "l"

for name, result in results.items():
    usecs = result * 1e6 / NUM  # Taken from timeit.py's CLI code.
    table.add_row([name, usecs])

print("Number of Calls: ", NUM)
print(table)
