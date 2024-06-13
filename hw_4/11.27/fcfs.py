import random
import sys


def fcfs_schedule(requests, start):

    total_head_movement = 0
    current_position = start

    for request in requests:
        total_head_movement += abs(request - current_position)
        current_position = request

    return total_head_movement


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python fcfs.py <initial_position>")
        sys.exit(1)
    initial_position = int(sys.argv[1])

    requests = random.sample(range(5000), 1000)

    movement = fcfs_schedule(requests, initial_position)

    print(f"Total head movement: {movement} cylinders")