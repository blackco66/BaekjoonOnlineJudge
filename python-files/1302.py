from collections import defaultdict


def best_seller(num_sold):
    book_count = defaultdict(int)
    for _ in range(num_sold):
        book_count[input()] += 1
    max_key = max(book_count.keys(), key=(lambda k: book_count[k]))
    max_val = book_count[max_key]
    for key, value in book_count.items():
        if value == max_val and key < max_key:
            max_key = key
    return max_key


if __name__ == "__main__":
    print(best_seller(int(input())))


# originally I tried
# max_key, max_val = max(book_count.items())
# for key, value in book_count.items():
# if value == max_val and key < max_key
#   max_key = key
# what was wrong with this?
