FROM ubuntu:20.04
RUN apt-get update
RUN apt-get install -y software-properties-common
RUN apt-get update


EXPOSE 60000

COPY source/serverMultmatrix /serverMultmatrix
RUN chmod +x /serverMultmatrix
CMD /serverMultmatrix

