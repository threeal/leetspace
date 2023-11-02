import os
import sys

import yaml

from .generators import generate_solution_cpp_src, generate_test_src


def main():
    with open(sys.argv[1], "r") as config_file:
        config = yaml.safe_load(config_file)

        if not os.path.exists(sys.argv[2]):
            os.makedirs(sys.argv[2])

        generate_solution_cpp_src(os.path.dirname(sys.argv[1]), sys.argv[2], config)
        generate_test_src(sys.argv[2], config)
