import sys

with open(sys.argv[2], "w") as dst:
    dst.write("#include <yaml-cpp/yaml.h>\n\n")
    dst.write("const auto test_cases = YAML::Load(R\"(\n")

    with open(sys.argv[1], "r") as src:
        dst.write(src.read())

    dst.write(")\");\n")
