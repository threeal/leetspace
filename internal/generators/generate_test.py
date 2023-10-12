import sys
import yaml

with open(sys.argv[1], 'r') as config_file:
    config = yaml.safe_load(config_file)
    name = config["name"]

    headers = {
        "<catch2/catch_test_macros.hpp>",
        "<yaml-cpp/yaml.h>",
        "<interface.hpp>",
        "<string>",
        "<vector>"
    }

    with open(sys.argv[2], "w") as output:
        for header in headers:
            output.write("#include %s\n" % header)

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

        output.write("\nTEST_CASE(\"%s\") {\n" % name)
        output.write("  for (const auto& [name, inputs, output] : test_cases) {\n")

        inputs = ", ".join(config["types"]["inputs"])
        output.write("    const auto [%s] = inputs;\n" % inputs)
        output.write("    CAPTURE(name, %s);\n\n" % inputs)

        for lang in config["solutions"]:
            output.write("    CHECK(solution_%s<%s>(%s) == output);\n" % (lang, config["types"]["output"], inputs))

        output.write("  }\n")
        output.write("}\n")
