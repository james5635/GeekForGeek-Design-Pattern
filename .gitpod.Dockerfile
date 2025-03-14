FROM gitpod/workspace-full
RUN apt update
RUN apt install -y libfmt-dev pkgconf
