import yaml
import sys

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
        output.write("  std::string name;\n")
        output.write("  YAML::Node data;\n")
        output.write("};\n")

        output.write("\nconst std::vector<TestCase> test_cases = {\n")
        for name in config["test_cases"]:
            output.write("  {\n")
            output.write("    .name = \"%s\",\n" % name)
            output.write("    .data = YAML::Load(R\"(\n")
            output.write(yaml.dump(config["test_cases"][name]))
            output.write("    )\")")
            output.write("  },\n")
        output.write("};\n")

        output.write("\nTEST_CASE(\"%s\") {\n" % name)
        output.write("  for (const auto& [name, data] : test_cases) {\n")

        variables = {}
        for v, t in config["types"]["inputs"].items():
            variables[v] = t
        variables["expected"] = config["types"]["output"]

        for v, t in variables.items():
            output.write("    const auto %s = data[\"%s\"].as<%s>();\n" % (v, v, t))

        inputs = ", ".join(config["types"]["inputs"])
        output.write("\n    CAPTURE(name, %s);\n" % inputs)
        for lang in config["solutions"]:
            output.write("    CHECK(solution_%s<%s>(%s) == expected);\n" % (lang, config["types"]["output"], inputs))

        output.write("  }\n")
        output.write("}\n")
