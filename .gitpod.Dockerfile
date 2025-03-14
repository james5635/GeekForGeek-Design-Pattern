FROM gitpod/workspace-full
RUN sudo apt update
RUN sudo apt install -y libfmt-dev pkgconf
