<?hh // strict

namespace Goul\Http;

use Psr\Http\Message\StreamInterface;

/**
 * TODO
 * {@inheritdoc}
 */
class Stream implements StreamInterface
{
    /**
     * {inheritdoc}
     */
    public function __toString(): string
    {
        return '';
    }

    /**
     * {inheritdoc}
     */
    public function close(): void
    {
    }

    /**
     * {inheritdoc}
     */
    public function detach(): ?resource
    {
        return null;
    }

    /**
     * {inheritdoc}
     */
    public function getSize(): ?int
    {
        return 0;
    }

    /**
     * {inheritdoc}
     */
    public function tell(): int
    {
        return 0;
    }

    /**
     * {inheritdoc}
     */
    public function eof(): bool
    {
        return true;
    }

    /**
     * {inheritdoc}
     */
    public function isSeekable(): bool
    {
        return true;
    }

    /**
     * {inheritdoc}
     */
    public function seek(int $offset, int $whence = SEEK_SET): void
    {
    }

    /**
     * {inheritdoc}
     */
    public function rewind(): void
    {
    }

    /**
     * {inheritdoc}
     */
    public function isWritable(): bool
    {
        return true;
    }

    /**
     * {inheritdoc}
     */
    public function write(string $string): int
    {
        return 0;
    }

    /**
     * {inheritdoc}
     */
    public function isReadable(): bool
    {
        return true;
    }

    /**
     * {inheritdoc}
     */
    public function read(int $length): string
    {
        return '';
    }

    /**
     * {inheritdoc}
     */
    public function getContents(): string
    {
        return '';
    }

    /**
     * {inheritdoc}
     */
    public function getMetadata(?string $key = null): mixed
    {
        return '';
    }
}
