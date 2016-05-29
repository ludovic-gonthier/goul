<?hh // strict

namespace Goul\Http;

use Psr\Http\Message\RequestInterface;
use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\UriInterface;

/**
 * {@inheritdoc}
 */
class Request extends Message implements RequestInterface
{
    public function __construct(
        private string $method,
        private UriInterface $uri,
        array<string, array<string>> $headers,
        StreamInterface $body,
        string $protocolVersion
    ) {
        parent::__construct($body, $headers, $protocolVersion);
    }

    /**
     * TODO
     * {@inheritdoc}
     */
    public function getRequestTarget(): mixed
    {
        return '';
    }

    /**
     * TODO
     * {@inheritdoc}
     */
    public function withRequestTarget(mixed $requestTarget): this
    {
        return $this;
    }

    /**
     * {@inheritdoc}
     */
    public function getMethod(): string
    {
        return $this->method;
    }

    /**
     * {@inheritdoc}
     */
    public function withMethod(string $method): this
    {
        $request = clone $this;
        $request->method = $method;

        return $request;
    }

    /**
     * {@inheritdoc}
     */
    public function getUri(): UriInterface
    {
        return $this->uri;
    }

    /**
     * {@inheritdoc}
     */
    public function withUri(UriInterface $uri, bool $preserveHost = false): this
    {
        $request = clone $this;
        $request->uri = $uri;

        return $request;
    }
}
