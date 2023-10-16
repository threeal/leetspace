import os
import sys
import yaml

with open(sys.argv[1], 'r') as config_file:
    config = yaml.safe_load(config_file)

    if not os.path.exists(sys.argv[2]):
        os.makedirs(sys.argv[2])

    with open(os.path.join(sys.argv[2], "solution_cpp.cpp"), "w") as output:
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

    with open(os.path.join(sys.argv[2], "test.cpp"), "w") as output:
        output.write("#include <catch2/catch_test_macros.hpp>\n")
        output.write("#include <string>\n")
        output.write("#include <vector>\n")

        output.write("\n")
        for lang in config["solutions"]:
            output.write("%s solution_%s(" % (config["types"]["output"], lang))
            output.write(", ".join([("%s %s" % (t, v)) for v, t in config["types"]["inputs"].items()]))
            output.write(");\n")

        output.write("\nstruct TestCase {\n")
        output.write("  struct Inputs {\n")
        for v, t in config["types"]["inputs"].items():
            output.write("    %s %s;\n" % (t, v))
        output.write("  };\n\n")
        output.write("  std::string name;\n")
        output.write("  Inputs inputs;\n")
        output.write("  %s output;\n" % config["types"]["output"])
        output.write("};\n")

        def dump(data):
            import json
            s = json.dumps(data)
            return s.replace("[", "{").replace("]", "}")

        output.write("\nconst std::vector<TestCase> test_cases = {\n")
        for name in config["test_cases"]:
            cfg = config["test_cases"][name]
            output.write("  {\n")
            output.write("    .name = \"%s\",\n" % name)
            output.write("    .inputs = {\n")
            for var, val in cfg["inputs"].items():
                output.write("      .%s = %s,\n" % (var, dump(val)))
            output.write("    },\n")
            output.write("    .output = %s\n" % dump(cfg["output"]))
            output.write("  },\n")
        output.write("};\n")

        for lang in config["solutions"]:
            output.write("\nTEST_CASE(\"%s (%s)\") {\n" % (config["name"], lang))
            output.write("  for (const auto& [name, inputs, output] : test_cases) {\n")

            inputs = ", ".join(config["types"]["inputs"])
            output.write("    const auto [%s] = inputs;\n" % inputs)
            output.write("    CAPTURE(name, %s);\n" % inputs)
            output.write("    CHECK(solution_%s(%s) == output);\n" % (lang, inputs))

            output.write("  }\n")
            output.write("}\n")
