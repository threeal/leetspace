FROM ubuntu:24.04

ARG RUNNER_VERSION=2.338.0
ARG RUNNER_SHA256=af4b794c1bc41d73d40535e3fe092a39f9679cd8d965954c2aca25a05ca41d32

RUN apt-get update \
  && apt-get install -y --no-install-recommends \
    clang \
    clang-format \
    cmake \
    git \
    ninja-build \
    python3-poetry \
  && rm -rf /var/lib/apt/lists/*

WORKDIR /home/ubuntu
ADD --checksum=sha256:${RUNNER_SHA256} --unpack=true --chown=ubuntu:ubuntu https://github.com/actions/runner/releases/download/v${RUNNER_VERSION}/actions-runner-linux-x64-${RUNNER_VERSION}.tar.gz .
RUN ./bin/installdependencies.sh \
  && rm -rf /var/lib/apt/lists/*

USER ubuntu
CMD ["./run.sh"]
