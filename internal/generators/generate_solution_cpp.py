import os
import sys
import yaml

with open(sys.argv[1], 'r') as config_file:
    config = yaml.safe_load(config_file)

    output_dir = os.path.dirname(sys.argv[2])
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    with open(sys.argv[2], "w") as output:
        if "cpp" in config["solutions"]:
            cfg = config["solutions"]["cpp"]

            if cfg is not None and "includes" in cfg:
                for include in cfg["includes"]:
                    output.write("#include <%s>\n" % include)
                output.write("\nusing namespace std;\n\n")

            with open(os.path.join(os.path.dirname(sys.argv[1]), "solution.cpp"), "r") as source:
                for line in source.readlines():
                    output.write(line)

            output.write("\n%s solution_cpp(" % config["types"]["output"])
            output.write(", ".join([("%s %s" % (t, v)) for v, t in config["types"]["inputs"].items()]))
            output.write(") {\n")

            output.write("  auto output = Solution().%s(" % cfg["function"])
            output.write(", ".join(config["types"]["inputs"]))
            output.write(");\n")

            output.write("  return %s;\n" % (cfg["output"] if "output" in cfg else "output"))

            output.write("}\n")
