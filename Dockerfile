FROM gcc:4.9
RUN mkdir /myapp
COPY . /myapp
WORKDIR /usr/src/myapp
RUN gcc -o myapp /myapp/class.cpp
CMD ["./myapp"]