import random
import sys


def scan_schedule(requests, start):
    total_head_movement = 0
    current_position = start

    left_requests = [r for r in requests if r < current_position]
    right_requests = [r for r in requests if r >= current_position]

    left_requests.sort(reverse=True)
    right_requests.sort()

    if left_requests and right_requests:
        total_head_movement += (right_requests[-1] - current_position) + (right_requests[-1] - left_requests[0])
        current_position = left_requests[0]
        total_head_movement += current_position - left_requests[-1]
    elif left_requests:
        total_head_movement += current_position - left_requests[-1]
    else:
        total_head_movement += right_requests[-1] - current_position

    return total_head_movement


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python scan.py <initial_position>")
        sys.exit(1)

    initial_position = int(sys.argv[1])

    requests = random.sample(range(5000), 1000)

    movement = scan_schedule(requests, initial_position)

    print(f"Total head movement: {movement} cylinders")