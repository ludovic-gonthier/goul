<?hh

// This file is not using strict mode because untyped arrays are required.

namespace Psr\Http\Message;

/**
 * TODO
 * {@inheritdoc}
 */
class ServerRequest extends Message implements ServerRequestInterface
{
    /**
     * {@inheritdoc}
     */
    public function getServerParams(): array<string, mixed>
    {
        return [];
    }

    /**
     * {@inheritdoc}
     */
    public function getCookieParams(): array<string, string>
    {
        return [];
    }

    /**
     * {@inheritdoc}
     */
    public function withCookieParams(array<string,string> $cookies): this
    {
        return $this;
    }

    /**
     * {@inheritdoc}
     */
    public function getQueryParams(): array
    {
        return [];
    }

    /**
     * {@inheritdoc}
     */
    public function withQueryParams(array<string,string> $query): this
    {
        return $this;
    }

    /**
     * {@inheritdoc}
     */
    public function getUploadedFiles(): array
    {
        return [];
    }

    /**
     * {@inheritdoc}
     */
    public function withUploadedFiles(array $uploadedFiles): this
    {
        return $this;
    }

    /**
     * {@inheritdoc}
     */
    public function getParsedBody(): mixed
    {
        return '';
    }

    /**
     * {@inheritdoc}
     */
    public function withParsedBody(mixed $data): this
    {
        return $this;
    }

    /**
     * {@inheritdoc}
     */
    public function getAttributes(): array<string, mixed>
    {
        return [];
    }

    /**
     * {@inheritdoc}
     */
    public function getAttribute(string $name, mixed $default = null): mixed
    {
        return '';
    }

    /**
     * {@inheritdoc}
     */
    public function withAttribute(string $name, mixed $value): this
    {
        return $this;
    }

    /**
     * {@inheritdoc}
     */
    public function withoutAttribute(string $name): this
    {
        return $this;
    }
}
