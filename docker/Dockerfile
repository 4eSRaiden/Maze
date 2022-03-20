FROM alpine:latest AS base

WORKDIR /maze

FROM base AS builder

RUN apk add --no-cache gcc musl-dev

COPY src/ ./src/
RUN gcc -Ofast -o ./maze-bin ./src/*

FROM base AS release

COPY --from=builder /maze/maze-bin ./maze-bin
COPY maps/ ./maps/

CMD [ "./maze-bin" ]
