import os


def generate_solution_cpp_src(source_dir: str, out_dir: str, config: any):
    with open(os.path.join(out_dir, "solution_cpp.cpp"), "w") as output:
        if "cpp" not in config["solutions"]:
            return

        cfg = config["solutions"]["cpp"]

        with open(os.path.join(source_dir, "solution.cpp"), "r") as source:
            for line in source.readlines():
                output.write(line)

        output.write("\n%s solution_cpp(" % config["types"]["output"])
        output.write(
            ", ".join(
                [("%s %s" % (t, v)) for v, t in config["types"]["inputs"].items()]
            )
        )
        output.write(") {\n")

        output.write("  auto output = Solution().%s(" % cfg["function"])
        output.write(", ".join(config["types"]["inputs"]))
        output.write(");\n")

        output.write(
            "  return %s;\n" % (cfg["output"] if "output" in cfg else "output")
        )

        output.write("}\n")
