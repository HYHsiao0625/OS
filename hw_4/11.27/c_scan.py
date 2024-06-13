import random
import sys


def cscan_schedule(requests, start):

    total_head_movement = 0
    current_position = start

    left_requests = [r for r in requests if r < current_position]
    right_requests = [r for r in requests if r >= current_position]

    left_requests.sort(reverse=True)
    right_requests.sort()

    if right_requests:
        total_head_movement += right_requests[-1] - current_position
        current_position = right_requests[-1]

    if left_requests:
        total_head_movement += (4999 - current_position) + 4999 - left_requests[0]
        current_position = left_requests[0]
        left_requests.pop()

    for request in reversed(left_requests):
        total_head_movement += abs(current_position - request)
        current_position = request

    return total_head_movement


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python cscan.py <initial_position>")
        sys.exit(1)

    initial_position = int(sys.argv[1])

    requests = random.sample(range(5000), 1000)

    movement = cscan_schedule(requests, initial_position)

    print(f"Total head movement: {movement} cylinders")