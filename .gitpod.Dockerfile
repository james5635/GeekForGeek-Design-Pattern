FROM gitpod/workspace-full
RUN apt update && apt install -y libfmt-dev pkgconf
