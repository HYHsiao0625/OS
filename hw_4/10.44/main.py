import random


def generate_page_reference_string(length=20):
    """Generate a random page-reference string with
    page numbers ranging from 0 to 9"""

    return [random.randint(0, 9) for _ in range(length)]


def fifo(pages, frames):
    """FIFO page replacement algorithm"""

    frame_set = set()
    page_faults = 0
    frame_buffer = []

    for page in pages:
        if page not in frame_set:
            page_faults += 1
            if len(frame_buffer) == frames:
                frame_set.remove(frame_buffer.pop(0))
            frame_set.add(page)
            frame_buffer.append(page)

    return page_faults


def lru(pages, frames):
    """LRU page replacement algorithm"""

    frame_set = set()
    page_faults = 0
    frame_buffer = []

    for page in pages:
        if page not in frame_set:
            page_faults += 1
            if len(frame_buffer) == frames:
                frame_set.remove(frame_buffer.pop(0))
        else:
            frame_buffer.remove(page)
        frame_set.add(page)
        frame_buffer.append(page)

    return page_faults


def optimal(pages, frames):
    """Optimal page replacement algorithm"""

    frame_set = set()
    page_faults = 0

    for i, page in enumerate(pages):
        if page not in frame_set:
            page_faults += 1
            if len(frame_set) == frames:
                future_pages = set(pages[i + 1 :])
                optimal_page_to_remove = max(
                    frame_set,
                    key=lambda p: (p not in future_pages, pages[i + 1 :].index(p) if p in future_pages else -1),
                )
                frame_set.remove(optimal_page_to_remove)
            frame_set.add(page)

    return page_faults


def main():
    """Main function"""

    pages = generate_page_reference_string()
    frames = int(input("Enter number of frames: "))

    print(f"Page reference string: {pages}")
    print(f"FIFO page faults: {fifo(pages, frames)}")
    print(f"LRU page faults: {lru(pages, frames)}")
    print(f"OPT page faults: {optimal(pages, frames)}")


if __name__ == "__main__":
    main()