<?hh // strict

namespace Goul\Http;

use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\MessageInterface;

abstract class Message implements MessageInterface
{
    public function __construct(
        protected StreamInterface $body,
        protected array<string, array<string>> $headers,
        protected string $protocolVersion
    ) {
    }

    /**
     * {@inheritdoc}
     */
    public function getProtocolVersion(): string
    {
        return $this->protocolVersion;
    }

    /**
     * {@inheritdoc}
     */
    public function withProtocolVersion(string $protocolVersion): this
    {
        $message = clone $this;
        $message->protocolVersion = $protocolVersion;

        return $message;
    }

    /**
     * {@inheritdoc}
     */
    public function getHeaders(): array<string, array<string>>
    {
        return $this->headers;
    }

    /**
     * {@inheritdoc}
     */
    public function hasHeader(string $name): bool
    {
        return array_key_exists(strtolower($name), $this->headers);
    }

    /**
     * {@inheritdoc}
     */
    public function getHeader(string $name): array<string>
    {
        $name = strtolower($name);
        if (!$this->hasHeader($name)) {
            return [];
        }

        return $this->headers[$name];
    }

    /**
     * {@inheritdoc}
     */
    public function getHeaderLine(string $name): string
    {
        $name = strtolower($name);
        if (!$this->hasHeader(strtolower($name))) {
            return '';
        }

        return implode(', ', $this->getHeader($name));
    }

    /**
     * {@inheritdoc}
     */
    public function withHeader(string $name, mixed $value): this
    {
        $message = clone $this;

        if (!is_string($value) && !is_array($value)) {
            throw new \InvalidArgumentException(); 
        }

        if (is_array($value)) {
            foreach ($value as $element) {
                if (!is_string($element)) {
                    throw new \InvalidArgumentException();
                }
            }

            $message->headers[$name] = $value;
        }

        if (is_string($value)) {
            $message->headers[$name] = [(string) $value];
        }

        return $message;
    }

    /**
     * TODO
     * {@inheritdoc}
     */
    public function withAddedHeader(string $name, mixed $value): this
    {
        return $this;
    }

    /**
     * TODO
     * {@inheritdoc}
     */
    public function withoutHeader(string $name): this
    {
        return $this;
    }

    /**
     * {@inheritdoc}
     */
    public function getBody(): StreamInterface
    {
        return $this->body;
    }

    /**
     * {@inheritdoc}
     */
    public function withBody(StreamInterface $body): this
    {
        $message = clone $this;
        $message->body = $body;

        return $message;
    }
}
